## 1340-Group-Project

Problem statement:
First problem is how to finding the available table. Second problem is how to determine the table occupied or not. Third problem is which table can be released. Fourth problem is how to choose the most suitable seats for the customers with minimal seats. Fifth problem is how to know the occupation time of each tables. Sixth problem is that the number of tables and the size of tables will be changed seasonally. 

Problem setting:
We assume that each seats is only available for one person. Child is also considered as one person. There is no customers occupying the table when changing the size and the number of tables. Also, the seat will be occupied if and only if the customer in on seat while the seat will be released if and only if the customer settles payment. When customers occupied a table, they cannot change the table.The maxium avaiable table in this restaurant is 20.

The function we want to implement is the reservation system which customers can book the table for a certain period. There is no customers add-on after confirming booking.

Functionalities and Features:
There are seven main functions of this program. First one is table setting. It can set the numbers of table from 0 to 20 and the size of the table from 0 to 2147483647.

Second function is display of table status. When second function is excuted, the content will be displayed in the fomrat below:

"Table no.": "size": "state: Available/ Not available"

Third function is table booking. User need to enter the table number which they want to book. If the table is not available at that time. It will display the "Failed. Table is not vacant". If it is available, the table will be booked and no other change can be made. Then, it will display "Continue? (Y/N): " for another booking. The booking of a book is only available for 1 hour before. It can book a table for 1 hour and it will release when 1 hour is end.

Fourth function is table releasing. User can change the table status from booked to available by entering the number of table. It will display "Continue? (Y/N): " for another table to be released.

Fifth function is finding available table. User need to enter the number of customers and the program will search the avaialbe table that the total number of customers can sit on.

Input/output specifications:

Compilation and Execution Instructions:
