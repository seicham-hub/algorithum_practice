import string
def ceasar_cipher_v1(text:str,shift:int)->str:
    result = ''
    for char in text:
        if char.isupper():
            alphabet = string.ascii_uppercase
        elif char.islower():
            alphabet = string.ascii_lowercase
        else:
            result += char
            continue
            
        index = (alphabet.index(char) + shift)%len(alphabet)
        result += alphabet[index]
    
    return result

def ceasar_cipher_v2(text:str,shift:int)->str:
    result = ''
    len_alphabet = ord('Z') - ord ('A') +1
    for char in text:
        if char.isupper():
            result += chr((ord(char) - ord('A') + shift)%len_alphabet +ord('A'))
        elif char.islower():
            result += chr((ord(char) - ord('a') + shift)%len_alphabet +ord('a'))
        else:
            result += char
    
    return result

from typing import Generator,Tuple

def caesar_cipher_hack(text:str)->Generator[Tuple[int,str],None,None]:

    len_alphabet = ord('Z') -ord('A')+1
    len_alphabet = len(string.ascii_uppercase)
    for candidate_shift in range(1,len_alphabet+1):
        reverted = ''
        for char in text:
            # if char.isupper():
            #     alphabet = string.ascii_uppercase
            # elif char.islower():
            #     alphabet = string.ascii_lowercase
            # else:
            #     reverted += char
            #     continue

            # index = alphabet.index(char) - candidate_shift
            # if index <0:
            #     index += len_alphabet
            # reverted += alphabet[index]

            if char.isupper():
                index = (ord(char) - candidate_shift) - ord('A')
                if index < 0:
                    index += len_alphabet
                reverted += chr(ord('A') + index)
            elif char.islower():
                index = (ord(char) - candidate_shift) - ord('a')
                if index < 0:
                    index += len_alphabet
                reverted += chr(ord('a') + index)
            else:
                reverted += char

        yield (candidate_shift,reverted)



if __name__ == '__main__':
    e = ceasar_cipher_v2('ATTACK BY SILICON VALLAY by engineer',3)
    print(e)
    for shift_num,decrypted in  caesar_cipher_hack(e):
        print(f"{shift_num}:2d",decrypted)
