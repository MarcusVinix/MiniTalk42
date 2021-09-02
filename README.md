# MiniTalk

## Description 
This project is about create a communication between a server and client, using signal UNIX.  
The server will be launched and display the pid, and whit that pid the client can send a message.


## How use
To use you just need create the compiled files server and client, executing make, this will create their both. First you will start the server `./server` the server will be started and the pid for the connection will show at terminal, now in another terminal you just need execute the client `./client PID "MESSAGE"` the message will appear int  the server terminal, enjoy!

## Bonus
* Unicode work.  
* The client received a signal from the server when the message is received.

