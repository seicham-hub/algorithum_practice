# 暗号化する文字 SILLICON VALLAYをkeyを使って暗号化
# keyは暗号化する文字と同じ長さで特定の文字が繰り返される（CATCATCAT等）
# 暗号化する際はkeyのインデックス分アルファベットをずらす

import string 

ALPHABET = string.ascii_uppercase

def generate_key(message:str,keyword:str):
    key = keyword
    remain_length = len(message) - len(keyword)

    for i in range(remain_length):
        key += key[i]
    
    return key

def encrypt(message:str,key:str) -> str:

    result = ''
    for i,char in enumerate(message):
        if char not in ALPHABET:
            result += char
            continue
        # index = (ALPHABET.index(char)+ALPHABET.index(key[i]))%len(ALPHABET)
        # result += ALPHABET[index]


        result += chr((ord(char) + ord(key[i])-2*ord('A'))%len(ALPHABET) +ord('A'))

    return result

def decrypt(cipher_text:str,key:str) ->str:

    result = ''   
    for i,char in enumerate(cipher_text):
        if char not in ALPHABET:
            result += char
            continue
        # index = (ALPHABET.index(char)-ALPHABET.index(key[i]) + len(ALPHABET))%len(ALPHABET)
        # result += ALPHABET[index]

        result += chr((ord(char) - ord(key[i]) + len(ALPHABET)) % len(ALPHABET) + ord('A'))
    return result



if __name__ == '__main__':
    msg = "SILLICON VALLAY"
    key = generate_key(msg,"CAT")
    e = encrypt(msg,key)
    print(e)
    print(decrypt(e,key))

