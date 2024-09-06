I had problems with curl library on my windows system so I decided to use docker
to solve that problem. Inside Dockerfile we can see which image I used and how
I did install curl library.

Because text from the given url have around 16 000 lines and 15 word in each line, I decided to set
capacity of hash table to be 25 % greater then 16000 x 15 = 240 000, so 

                    240 000 x 1.25 = 300 000.

It is good to choose capacity of a hash table to be prime number closest and greater then 300 000.
So I decided to set capacity to 300 007 which is prime number.

downloader.cpp is a file where i wrote function to fetch text from the given url in the task.

Hashtable is a class where I defined methods like insert, remove, get, get_last, and_get_first.

At first I wanted to implement soultion where keys are words from a text and values are frequencies
(how many time each word appear in the text). In that scenario we dont need to have int value as
argumnet in method insert(key, value), because if i find word in a text for the first time I can
set frequency of that word to 1, but if a already found same word before then I can just upadate
frequency (like frequency[word] += 1). At the end I gave up on such implementation because I wanted
to have insert with to parameters (key, value). In my opinion for values I can choose random number,
so  everytime when we process word we can set new random number to that word.

My implementation of get_first and get_last method are based on function process file where as argument
I send hash_table. hash_table has attribute updateOrder (it is a list of string) where I can track which
word was most recently inserted and which is least recently inserted.

Maybe better approach would be to track most/least recently word updated in insert(key, value) method
so i dont need to send hash table as a argumnet to method process file.

I also decided to clean words from text and only to keep alphanumeric charcters.

To reduce collisions in hash table very important is which hash function we use. I decide
to use standard library hash function which is highly optimized.

In my mathods of Hash table class (insert, helper method findKey) I have while loop and in the task
condition is time complexity of O(1), constant time. But with good hash function and low number of
collisions in average case program even do not enter into while loop or program iterate through while
loop just few times. In case of no collisions complexity of insert and findKey are O(1).

To execute code run: docker-compose build and then docker-compose up.



