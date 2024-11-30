# Homework 6: Design Document
    * author: *Arjun Taneja*
    * date: November 25 2024

# Function 1: Score letter

For this function, I will use a loop to go through each word in the vocabulary and check if the given letter exists in the word. I will initialize a counter variable to 0 before the loop and increment it inside the loop if the letter is found. At the end, I will return the counter value as the result.

# Function 2: Score word

For this function, I will iterate through the word using a loop and calculate the score for unique letters by checking each character against the rest of the word before it. If the character hasn't appeared earlier in the word, I will add its corresponding score from the letter scores array. Finally, I will return the total score for that word.

# Function 3: Filter vocabulary gray

For this function, I will iterate over the vocabulary using a loop and check if the letter passed as a parameter to this function exists in each word. If the letter is found, I will free the pointer to that word and set its corresponding slot to NULL, and increment a counter. At the end, I will return the counter which will represent the number of words I filtered out.

# Function 4: filter vocabulary yellow

For this function, I will iterate over the vocabulary using a loop and check if the letter passed as a parameter to this function exists in each word. If the letter does not exist or is in the same index as the letter, I will free the pointer to that word and set its corresponding slot to NULL, and increment a counter. At the end, I will return thecounter which will represent the number of words I filtered out.

# Function 5: filter vocabulary green

For this function, I will iterate over the vocabulary using a loop and check if the letter passed as a parameter to this function exists in each word. If the letter does not exist and is not in the same index as the letter, I will free the pointer to that word and set its corresponding slot to NULL, and increment a counter. At the end, I will return the counter which will represent the number of words I filtered out.
