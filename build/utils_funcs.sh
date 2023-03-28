#!/bin/bash
###
 # COPYRIGHT NOTICE
 # Copyright 2023 Horizon Robotics, Inc.
 # All rights reserved.
 # @Date: 2023-03-28 20:07:38
 # @LastEditTime: 2023-03-28 20:11:49
### 

function lunch_usage()
{
    echo "[Error] Options not supported"
    echo "Options should be a valid integer or name of board config."
    echo "Usage: "
    echo "    ./xbuild.sh lunch [0-9]/[name of board config]"
    echo "    ./xbuild.sh lunch"
    echo "    ./xbuild.sh lunch 1"
    echo "    ./xbuild.sh lunch board_config.mk"
    echo
    exit -1
}

function lunch_board_combo()
{
    local uname=$(uname -v)
    echo
    echo "You're building on" $uname

    LUNCH_MENU_CHOICES=( $(cd ${HR_TOP_DIR}/device; find -iname  board*.mk | cut -c 3- | sort) )
    BOARD_CONFIG=${HR_TOP_DIR}/device/.board_config.mk

    if [ $# == 0 ]; then
        echo "Lunch menu... pick a combo:"
     
        local i=0 
        local choice
        for choice in ${LUNCH_MENU_CHOICES[@]}
        do  
            echo "      $i. $choice"
            i=$(($i+1))
        done

        local answer
        echo -n "Which would you like? [0] : "
        read answer

        if echo $answer | grep -vq [^0-9]; then
            echo "You are selected board config: ${LUNCH_MENU_CHOICES[answer]}"
            ln -rfs  ${HR_TOP_DIR}/device/${LUNCH_MENU_CHOICES[answer]} $BOARD_CONFIG
        else
            echo "[Error] The input is not a integer."
            echo "Please input a valid integer."
            echo
            exit -1
        fi
    elif [ $# == 1 ]; then
        if echo $1 | grep -vq [^0-9]; then
            if [ $1 -ge ${#LUNCH_MENU_CHOICES[@]} ]; then
                echo "Option '$1' out of range, please retry"
                echo
                exit -1
            fi
            echo "You are selected board config: ${LUNCH_MENU_CHOICES[$1]}"
            ln -rfs  ${HR_TOP_DIR}/device/${LUNCH_MENU_CHOICES[$1]} $BOARD_CONFIG
        else
            if [[ ! "${LUNCH_MENU_CHOICES[@]}" =~ ${1} ]]; then
                echo "Board config '$1' not found."
                echo "You should select config from the following configurations:"
                i=0
                for choice in ${LUNCH_MENU_CHOICES[@]}
                do  
                    echo "      $i. $choice"
                    i=$(($i+1))
                done
                echo
                exit -1
            fi
            i=0
            for choice in ${LUNCH_MENU_CHOICES[@]}
            do
                if [[ "${choice}" =~ ${1} ]]; then
                    echo "You are selected board config: ${choice}"
                    ln -rfs  ${HR_TOP_DIR}/device/${choice} $BOARD_CONFIG
                    break
                fi
                i=$(($i+1))
            done
        fi
    else
        lunch_usage
    fi
    echo
}

function check_board_config()
{
    if [ $# == 1 ];then
        if [ $1 = "clean" ] || [ $1 = "distclean" ];then
            return 0
        fi
    fi
    BOARD_CONFIG=${HR_TOP_DIR}/device/.board_config.mk
    [ ! -L "$BOARD_CONFIG" ] && {
        lunch_board_combo
    }

    [ -z "$HR_IS_BOARD_CONFIG_EXPORT" ] && source $BOARD_CONFIG

    return 0
}

function cpfiles()
{
    if [ $# -ne 2 ];then
        echo "Usage: cpfiles \"sourcefiles\" \"destdir\""
        exit 1
    fi

    mkdir -p $2 || {
        echo "mkdir -p $2 failed"
        exit 1
    }

    for f in $1
    do
        if [ -a $f ];then
            cp -af $f $2 || {
                echo "cp -af $f $2 failed"
                exit 1
            }
        fi
    done
    echo "cpfiles $1 $2"
}

function move_file()
{
    target_root=$1
    manifest=$2
    cat ${manifest} | while read file;
    do
        src_file=${file%=>*}
        dst_file=${file#*=>}
        echo "mv ${src_file} => ${dst_file}"
        mv ${target_root}/${src_file} ${target_root}/${dst_file}
    done
}

function inList()
{
    if [ $# -ne 2 ];then
        echo "Usage: inList element list"
        exit 1
    fi

    local arr=$2
    local result=1
    local elem

#    echo "arr: ${arr[*]}"
    for elem in ${arr[*]}
    do
        #echo "elem:$elem, \$1=$1"
        if [ "$elem" = "$1" ];then
            #echo "result is 0"
            result=0
            break
       fi
    done

    return $result
}

function runcmd()
{
    if [ $# -ne 1 ];then
        echo "Usage: runcmd command_string"
        exit 1
    fi

    echo "$1"
    $1 || {
        echo "failed"
        exit 1
    }
}

function trans_unit()
{
    local num=$1
    local c=${num:0-1}
    num=$(echo $num | tr "[A-Z]" "[a-z]")

    if [ -z "$(echo $c | sed 's#[0-9]##g')" ];then
        echo "$((${num}/512))"
    elif [ "$c" = "k" ];then
        echo "${num:0:0-1}*2"
    elif [ "$c" = "m" ];then
        echo "${num:0:0-1}*2*1024"
    elif [ "$c" = "g" ];then
        echo "${num:0:0-1}*2*1024*1024"
    elif [ "$c" = "s" ];then
        echo "${num:0:0-1}"
    else
        echo "Error: Unknown size [$1]"
        exit 1
    fi
}
