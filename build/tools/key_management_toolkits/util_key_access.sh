get_rom_rsa_key=0
get_rom_aes_key=0
get_efuse_key=0
get_spl_key=0
get_bpu_key=0

while getopts "rtb:RAESB" opt; do
  case $opt in
       r)  # get key from kms with real rom key
           get_rom_key=1
           fallback_key=0
           ;;
       t)  # get key from kms with test key
           get_rom_key=0
           fallback_key=0
           ;;
       b)  # use fallback key directlly
           get_rom_key=0
           fallback_key=1
           fallback_key_loc=$OPTARG
           ;;
       R)
           get_rom_rsa_key=1
           ;;
       A)
           get_rom_aes_key=1
           ;;
       E)
           get_efuse_key=1
           ;;
       S)
           get_spl_key=1
		   ;;
	   B)
	   	   get_bpu_key=1
           ;;
       h)
           helper
           exit
           ;;
      \?)
      echo "Invalid option: -$OPTARG" >&2
      ;;
  esac
done

echo get_rom_key = $get_rom_key
echo fallback_key = $fallback_key
echo get_rom_rsa_key = $get_rom_rsa_key
echo get_rom_aes_key = $get_rom_aes_key
echo get_efuse_key = $get_efuse_key
echo get_spl_key = $get_spl_key
echo fallback_key_loc = $fallback_key_loc
echo get_bpu_key = $get_bpu_key

oops()
{
	oop=1
	echo something wrong ...
	while [ $oop -eq "1" ]
	do
		sleep 1
	done
}


##############################################
# main logic
##############################################

# Get rom rsa public key and priv key if fallback key
if [ "$get_rom_rsa_key" -eq "1" ]; then
    if [ "$get_rom_key" -eq "1" ]; then
		folder_exist=0
		test -d key_list && folder_exist=1

		if [ "$folder_exist" -eq "0" ]; then
		    echo folder not exist, we pull new
		    git clone git@10.104.34.40:/home/git/key_list.git
		fi

		. key_list/rom/access_key.list

 	        ./kms_util -u $account -a $ak_rom_rsa_key0 -p rom_rsa0_pub.pem
        	openssl rsa -pubin -inform PEM -in rom_rsa0_pub.pem -outform DER -out rom_rsa0_pub.der
    		dd if=rom_rsa0_pub.der of=rom_rsa0_pub.bin bs=1 count=256 skip=33 status=none
		rm rom_rsa0_pub.der rom_rsa0_pub.pem

	        ./kms_util -u $account -a $ak_rom_rsa_key1 -p rom_rsa1_pub.pem
	        openssl rsa -pubin -inform PEM -in rom_rsa1_pub.pem -outform DER -out rom_rsa1_pub.der
	        dd if=rom_rsa1_pub.der of=rom_rsa1_pub.bin bs=1 count=256 skip=33 status=none
		rm rom_rsa1_pub.der rom_rsa1_pub.pem
	
	        ./kms_util -u $account -a $ak_rom_rsa_key2 -p rom_rsa2_pub.pem
	        openssl rsa -pubin -inform PEM -in rom_rsa2_pub.pem -outform DER -out rom_rsa2_pub.der
	        dd if=rom_rsa2_pub.der of=rom_rsa2_pub.bin bs=1 count=256 skip=33 status=none
		rm rom_rsa2_pub.der rom_rsa2_pub.pem
	
		./kms_util -u $account -a $ak_rom_rsa_key3 -p rom_rsa3_pub.pem
	        openssl rsa -pubin -inform PEM -in rom_rsa3_pub.pem -outform DER -out rom_rsa3_pub.der
	        dd if=rom_rsa3_pub.der of=rom_rsa3_pub.bin bs=1 count=256 skip=33 status=none
		rm rom_rsa3_pub.der rom_rsa3_pub.pem
	
	        ./kms_util -u $account -a $ak_rom_rsa_key4 -p rom_rsa4_pub.pem
	        openssl rsa -pubin -inform PEM -in rom_rsa4_pub.pem -outform DER -out rom_rsa4_pub.der
	        dd if=rom_rsa4_pub.der of=rom_rsa4_pub.bin bs=1 count=256 skip=33 status=none
		rm rom_rsa4_pub.der rom_rsa4_pub.pem
		
    elif [ "$fallback_key" -eq "0" ]; then
        echo bbb
		# ADD:
		# cp $fallback_key_loc if fail to get key from kms
	else
        cp $fallback_key_loc/rom_rsa*_pub.bin	.
        cp $fallback_key_loc/rom_rsa*_priv.pem  .
    fi
fi

# Get rom aes key/iv
if [ "$get_rom_aes_key" -eq "1" ]; then
    if [ "$get_rom_key" -eq "1" ]; then
        #./kms_util -u $account -a $ak_rom_aes_key           -p $rom_aes_key_name.key.b64    -e
        #sh base64_to_hex.sh $rom_aes_key_name.key.b64       $rom_aes_key_name.key

	folder_exist=0
	test -d key_list && folder_exist=1

	if [ "$folder_exist" -eq "0" ]; then
	    echo folder not exist, we pull new
	    git clone git@10.104.34.40:/home/git/key_list.git
	fi

	. key_list/rom/access_key.list

        ./kms_util -u $account -a $ak_rom_aes_key           -p rom_aes.key.b64    -e
        sh base64_to_hex.sh rom_aes.key.b64       rom_aes.key
	rm rom_aes.key.b64

	./kms_util -u $account -a $ak_rom_aes_iv           -p rom_aes.iv.b64    -e
        sh base64_to_hex.sh rom_aes.iv.b64       rom_aes.iv
	rm rom_aes.iv.b64

        #./kms_util -u $account -a $ak_rom_aes_iv            -p $rom_aes_key_name.iv.b64     -e
        #sh base64_to_hex.sh $rom_aes_key_name.iv.b64        $rom_aes_key_name.iv
    elif [ "$fallback_key" -eq "0" ]; then
		echo bbb
		# ADD:
		# cp $fallback_key_loc if fail to get key from kms
	else
        cp $fallback_key_loc/rom_aes*	.
    fi
fi

# Get efuse aes key and rsa4 pub hash
if [ "$get_efuse_key" -eq "1" ]; then
    if [ "$get_rom_key" -eq "1" ]; then

        folder_exist=0
        test -d key_list && folder_exist=1

        if [ "$folder_exist" -eq "0" ]; then
            echo folder not exist, we pull new
            git clone git@10.104.34.40:/home/git/key_list.git
        fi

	. key_list/rom/access_key.list
	
        ./kms_util -u $account -a $ak_efuse_aes_key -p efuse_aes.key.b64    -e
        sh base64_to_hex.sh efuse_aes.key.b64       efuse_aes.key
	rm efuse_aes.key.b64

        ./kms_util -u $account -a $ak_efuse_aes_iv  -p efuse_aes.iv.b64    -e
        sh base64_to_hex.sh efuse_aes.iv.b64        efuse_aes.iv
	rm efuse_aes.iv.b64

        ./kms_util -u $account -a $ak_rom_rsa_key4 -p rom_rsa4_pub.pem
        openssl rsa -pubin -inform PEM -in rom_rsa4_pub.pem -outform DER -out rom_rsa4_pub.der
        dd if=rom_rsa4_pub.der of=rom_rsa4_pub.bin bs=1 count=256 skip=33 status=none
        rm rom_rsa4_pub.der rom_rsa4_pub.pem
        openssl dgst -sha256 -binary -out efuse_rom_rsa4_pub.bin.hash rom_rsa4_pub.bin


        #./kms_util -u $account -a $ak_rom_aes_key           -p $rom_aes_key_name.key.b64    -e
        #sh base64_to_hex.sh $rom_aes_key_name.key.b64       $rom_aes_key_name.key

        #./kms_util -u $account -a $ak_rom_aes_iv            -p $rom_aes_key_name.iv.b64     -e
        #sh base64_to_hex.sh $rom_aes_key_name.iv.b64        $rom_aes_key_name.iv
    elif [ "$fallback_key" -eq "0" ]; then
		echo bbb
		# ADD:
		# cp $fallback_key_loc if fail to get key from kms
	else
        cp $fallback_key_loc/efuse_aes*	. 
        cp $fallback_key_loc/rom_aes.*  .
        openssl dgst -sha256 -binary -out efuse_rom_rsa4_pub.bin.hash $fallback_key_loc/rom_rsa4_pub.bin
    fi
fi

# Get spl aes key and spl pub key
if [ "$get_spl_key" -eq "1" ]; then
    if [ "$get_rom_key" -eq "1" ]; then

        folder_exist=0
        test -d key_list && folder_exist=1

        if [ "$folder_exist" -eq "0" ]; then
            echo folder not exist, we pull new
            git clone git@10.104.34.40:/home/git/key_list.git
        fi

	    . key_list/spl/access_key.list

        ./kms_util -u $account -a $ak_spl_aes_spl_img_key -p spl_aes_spl_img.key.b64    -e
        sh base64_to_hex.sh spl_aes_spl_img.key.b64       spl_aes_spl_img.key

        ./kms_util -u $account -a $ak_spl_aes_spl_img_iv -p spl_aes_spl_img.iv.b64    -e
        sh base64_to_hex.sh spl_aes_spl_img.iv.b64       spl_aes_spl_img.iv
 
        ./kms_util -u $account -a $ak_spl_rsa_key -p spl_rsa_spl_img_pub.pem
        openssl rsa -pubin -inform PEM -in spl_rsa_spl_img_pub.pem -outform DER -out spl_rsa_spl_img_pub.der
        dd if=spl_rsa_spl_img_pub.der of=spl_rsa_spl_img_pub.bin bs=1 count=256 skip=33 status=none
        rm spl_rsa_spl_img_pub.der spl_rsa_spl_img_pub.pem
    
        #sh base64_to_hex.sh $rom_aes_key_name.iv.b64        $rom_aes_key_name.iv
		echo aaa
    elif [ "$fallback_key" -eq "0" ]; then
		echo bbb
		# ADD:
		# cp $fallback_key_loc if fail to get key from kms
	else
        cp $fallback_key_loc/spl_aes_spl_img.*	. 
        cp $fallback_key_loc/spl_rsa_spl_img_p*	. 
    fi
fi

# Get bpu aes key and bpu pub key
if [ "$get_bpu_key" -eq "1" ]; then
    if [ "$get_rom_key" -eq "1" ]; then
        #./kms_util -u $account -a $ak_rom_aes_key           -p $rom_aes_key_name.key.b64    -e
        #sh base64_to_hex.sh $rom_aes_key_name.key.b64       $rom_aes_key_name.key
        cp $fallback_key_loc/spl_aes_bpu_img.*	. 
        cp $fallback_key_loc/spl_rsa_bpu_img_p*	. 
        #./kms_util -u $account -a $ak_rom_aes_iv            -p $rom_aes_key_name.iv.b64     -e
        #sh base64_to_hex.sh $rom_aes_key_name.iv.b64        $rom_aes_key_name.iv
		echo aaa
    elif [ "$fallback_key" -eq "0" ]; then
		echo bbb
		# ADD:
		# cp $fallback_key_loc if fail to get key from kms
	else
        cp $fallback_key_loc/spl_aes_bpu_img.*	. 
        cp $fallback_key_loc/spl_rsa_bpu_img_p*	. 
    fi
fi

