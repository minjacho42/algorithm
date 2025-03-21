from collections import deque

def stepper(word, word_len):
    que = deque(word)
    pop_idx = range(word_len - 2 if word_len % 2 == 1 else word_len - 3, 0, -2)
    for i in pop_idx:
        que.append(que[i])
    for i in pop_idx:
        del que[i]
    return ''.join(que)

X = int(input())
word = input()
word_len = len(word)

step_words = [word, ]
stepped_word = word

while True:
    stepped_word = stepper(stepped_word, word_len)
    if stepped_word == word:
        break
    else:
        step_words.append(stepped_word)
print(step_words[X % len(step_words)])