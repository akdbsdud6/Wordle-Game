1. score_guess
- this function has two purposes:
1) return true / false if guess == secret or not.
2) fill result with 'x', 'y', or 'g'.

- for 1), I would use a bool same. Using a for loop, I will go over every character of guess and secret. If at least one character in guess does not match that of secret, same = false. 
- 2) can be done with 2 for loops. If guess[i] and secret[i] are the same, it fills the spot of result[i] with 'g'. If the character
in guess is not at the same spot in secret, I check if guess[i] matches secret[j]. If guess[i] == secret[j], result[i] = 'y'. If none of secret[j] == guess[i], it fills the spot of result with 'x'.

2. valid_guess
- this function also has two for loops. One to iterate each word inside the vocabulary, and one to iterate each character of a word.
I used bool same like I did in score_guess. For every line i and every character of the string in line i, it checks if guess[j] == vocabulary[i][j]. If it checks that at least one character isn't matching,
it will keep searching. 
As soon as it finds a word inside the vocabulary that matches exactly with the guess, it returns true. If the loop ends without it finding a matching word in the vocabulary, it returns false.

3. load_vocabulary
- First, I allocate memory for out, the amount for 10 (char *) to fit. The reason I do 10 is so that I don't have to reallocate it every time, but every 10 times. 
Then, I initialize: int memory, which will be used as an increment for realloc; temp, which will be used as buffer for fgets. Next, I fopen the file, fgets to get the words into temp, and strndup it to out[*num_words].
When done, fclose the file. 

4. free_vocabulary
- With a for loop, I will iterate the vocabulary loaded from load_vocabulary and free every vocabulary[i]. Then, I will free the whole vocabulary array.