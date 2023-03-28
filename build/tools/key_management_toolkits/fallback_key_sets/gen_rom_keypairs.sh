
#$1: rsa key name prefix
get_rsa_key_pairs()
{
	openssl genrsa -out $1_priv.pem 2048
	openssl rsa -in $1_priv.pem -pubout -out $1_pub.pem
	openssl rsa -pubin -inform PEM -in $1_pub.pem -outform DER -out $1_pub.der
	dd if=$1_pub.der of=$1_pub.bin bs=1 count=256 skip=33
}

#$1: aes key name
gen_aes_key()
{
	openssl rand 16 > $1
}

get_rsa_key_pairs rom_rsa0
get_rsa_key_pairs rom_rsa1
get_rsa_key_pairs rom_rsa2
get_rsa_key_pairs rom_rsa3
get_rsa_key_pairs rom_rsa4

gen_aes_key rom_aes.key
gen_aes_key rom_aes.iv
