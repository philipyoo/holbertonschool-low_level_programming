# C - Variables, If, Else, While

### 0. Postive anything is better than negative nothing
Based on the [source code](https://github.com/holbertonschool/0x01.c/blob/master/0-positive_or_negative_c), add code that will print whether the number stored in the variable `n` is positive or negative.
I used conditionals to print results.

### 1. The last digit
Based on the [source code](https://github.com/holbertonschool/0x01.c/blob/master/1-last_digit_c), add code to print the last digit of the number stored in variable `n`.
I used conditionals and printf statements to determine the print results.

### 2. I sometimes suffer from insomnia. And when I can't fall asleep, I play what I call the alphabet game
Write a program that prints the alphabet in lowercase, followed by a new line.
In C, `char` types can handle arithmetic operations using their ASCII values. Knowing this, we can create loops that can increment or decrement the `char` values which can be translated back into a letter if needed.

### 3. alphABET
Write a program that prints the alphabet, in lowercase, and then in uppercase, followed by a new line.
I used a brute force method where I just looped through for the lowercase, reset the variable for uppercase, and looped again.

### 4. When I was having that alphabet soup, I never thought that it would pay off
Write a program that prints the alphabet in lowercase, followed by a new line.
Print all letters except for 'q' and 'e'.
Similar to the past exercises, I looped through and printed each char and had a conditional that would pass over 'q' and 'e'.

### 5. Numbers
Write a program that prints all numbers of base 10, starting from 0, followed by a new line.
Using a loop, I can increment my variable that holds the current number, starting with 0. The restriction for this one was I had to use `putchar`. In order for me to convert the number into ASCII, I added `0` to each number within the `putchar` method.

### 6. Numberz
Write a program that prints all numbers of base 10 starting from 0, followed by a new line. You are not allowed to use `char` variables.
Similar to exercise 5, I converted each number to ASCII for `putchar`.

### 7. Smile in the mirror
Write a program that prints the alphabet, in reverse order, in lowercase.
A cool thing you can do here is loop but in reverse using a decrement.

### 8. Hexadecimal
Write a program that prints all the numbers of base 16 in lowercase.
I simply used 2 separate loops, one for the numbers, and one for the letters.

### 9. Patience, persistence and perspiration make an unbeatable combination for success
Write a program that prints all possible combinations of single-digit numbers, separated by a comma and a space. 
I created an `int` to increment up within a loop and just print the number and the comma and space. I also needed an `if` conditional to ignore the last comma and space for the last number.

### 10. 00...99
Write a program that prints numbers from 0 to 99. Single digit numbers must be preceded with a 0. Numbers should be comma and space separated.
Using 3 `int` variables, I used one variable to count up to 99, and the other 2 variables to store the doubles digit and the singles digit. Using these separate numbers, I printed them out adjacent and with a comma and space after them. Adding another if conditional for the last number so that a comma and space isn't added at the very end.

### 11. Inventing is a combination of brains and materials. The more brains you use, the less material you need
Write a program that prints all possible different combinations of two digits. Numbers should be separated by a comma and space, and numbers with the same digits but in different order should not be printed twice.
Similar to exercise 10, I used variables to store the doubles digit and singles digit. The pattern here was to keep incrementing the doubles digit and making sure that the singles digit was larger than the doubles digit.

### 12. The success combination in business is: Do what you do better... and: do more of what you do..
Write a program that prints all possible different combinations of three digits. Similar to exercise 11.
Using the same process as exercise 11, but with an additional variable to track the hundreds position.

### 13. Software is eating the World
Write a program that prints all possible combinations of two two-digit numbers. All number combinations should be separated by a space.
This one was tricky. However, creating more variables to store each 2 digit number helped a lot in order to make comparisons. Using 2 loops, we can loop up the first double digit number, and the inner loop can increment up the second double digit number. Add an if conditional to make sure that the first double digit number isn't "98", so we don't add a comma and space at the end.
