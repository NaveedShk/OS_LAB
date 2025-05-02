TASK 01:
![image](https://github.com/user-attachments/assets/075f0e4e-94f0-4ea1-ae5b-e27ca197d38e)

TASK 02:
```
read -p "Enter the sentence: " sentence

vow=0
len=${#sentence}

for ((i = 0; i < $len; i++))
do
    char=${sentence:$i:1}

    if [[ $char == "a" || $char == "e" || $char == "i" || $char == "o" || $char == "u" || $char == "A" || $char == "E" || $char == "I" || $char == "O" || $char == "U" ]];
    then
        ((vow++))
    fi
done

echo "Number of vowels: $vow"
```
![image](https://github.com/user-attachments/assets/58018ce9-ce21-4d01-a62e-06c031ec3af6)


TASk 03:
![image](https://github.com/user-attachments/assets/62b832d5-b1ca-47b9-b584-845d88ffa668)

Task 04:
![image](https://github.com/user-attachments/assets/2030e8c0-575e-4d15-a6f2-0c4ceaa7f86f)

![image](https://github.com/user-attachments/assets/611cc4ee-2cc2-418e-ba83-0aeb0cfc24b0)

Task 5:
![image](https://github.com/user-attachments/assets/31690acc-190a-4ff5-bc6b-ce236e601c59)
![image](https://github.com/user-attachments/assets/393c76d0-72a9-4127-abb5-01b41cac071f)


