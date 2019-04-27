## 1340-Group-Project

Problem statement:
First problem is how to finding the available table. Second problem is how to determine the table occupied or not. Third problem is which table can be released. Fourth problem is how to choose the most suitable seats for the customers with minimal seats. Fifth problem is how to know the occupation time of each tables. Sixth problem is that the number of tables and the size of tables will be changed seasonally. 

Problem setting:
We assume that each seats is only available for one person. Child is also considered as one person. There is no customers occupying the table when changing the size and the number of tables. Also, the seat will be occupied if and only if the customer in on seat while the seat will be released if and only if the customer settles payment. When customers occupied a table, they cannot change the table.The maxium avaiable table and the size of table in this restaurant is 20. 

The function we want to implement is the reservation system which customers can book the table for a certain period. There is no customers add-on after confirming booking.

Functionalities and Features:

There are seven main functions of this program.

First function is display of table status. When function is excuted, the content of the table will be displayed included table number, size, time for occupation or booked and table status.

Second function is table occupying. When a customers is arrived the restaurant without booking, it can be provided an available table by this function. User need to enter the table number and the table status will be changed to occupied.

Third function is table releasing. User can change the table status from booked to available by entering the number of table. It will display "Continue? (Y/N): " for another table to be released. 

Fourth function is finding available table. User need to enter the number of customers and the program will search the avaialbe table that the total number of customers can sit on. If there is no avaiable table, it will display "No available table is found."

Fifth function is table booking. User need to enter the personal information such as name and phone. Then, user can enter the table which they want to book. If the table is not available at that time, it will display the "Failed. Table is not vacant". If it is available, the table will be booked and no other change can be made. The booking record will be stored in the "Booking.txt" with format "Name: Phone No.: Table No.: ". Then, it will display "Continue? (Y/N): " for another booking. The booking service of a table is only available for a hour before the meal and no future booking is allowed. It can book a table for 1 hour and it will be released after an hour.

Sixth function is Release Booking. User can cancel a booking or indicate that the customer is arrived. If it is cancellation of booking, it will required user to enter the table number and release the table status from booked to avaiable. If customer is arrived, it will also required user to enter the table number and change the table status from booked to occupied.

Seventh function is Table setting. It can set or reset the numbers of table from 0 to 20 and the size of the table from 0 to 20.

Input/output specifications:
User always input the correct input. For table booking function, user need to input the name in capital letter. For output, there will be a "Booking.txt" after the table booking function is executed.
For example:
Name: Chan Tai Man Phone No.:12345678 Table No.: 1

Compilation and Execution Instructions:
After the user input the value, they have to press "enter" to execute the program.
