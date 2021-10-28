# producer_consumer_problem

 By Ramone Fields

# Getting Started

This project is to show how to solve the Proudcer-Cosumer Problem. This project shows the producer consumer problem using mutex and semaphores sharing memory. We use semaphores to synchronize producer and consumer. Mutual exclusion should be considered. We use pthreads in the producer program and consumer program.

# How to run/complie with the following commands. 
1. gcc producer.c -pthread -lrt -o producer
2. gcc consumer.c -pthread -lrt -o consumer
3. ./producer & ./consumer &

Exit the program run with 
ctrl+c on windows/ MacOs command+c

# Example Output 
<img width="375" alt="Screen Shot 2021-10-28 at 5 59 10 PM" src="https://user-images.githubusercontent.com/88847535/139342258-8da4f53a-5306-432e-b01e-bc33981a9aea.png">

# References
https://man7.org/linux/man-pages/man3/shm_open.3.html

