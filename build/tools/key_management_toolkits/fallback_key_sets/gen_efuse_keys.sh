#$1: aes key name
gen_aes_key()
{
	openssl rand 16 > $1
}

gen_aes_key efuse_aes.key
