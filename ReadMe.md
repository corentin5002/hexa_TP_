# TP1 : Calendar 

## How to compile and launch the program

Execute `make` in the project folder and then execute with `./main`

## Unit tests

### Test if a new event is added correctly to the calendar.

We create a new event and add it to the calendar.
```
[18:53:02] : hexa_TP_ $ ./main


You are working with the calendar named : no named calendar
Here are the options available : 

0 - Add an event to your current calendar
1 - Remove an event from your agenda
2 - Show the calendar
3 - Load a calendar
4 - Export your calendar
5 - Quit the application
Current agenda used : "no named calendar"

Enter a number between 0 and 5: 0


Add an event to your current calendar

Enter the date of the event with this format : 'dd/mm/yyyy'
-> : 28/01/2024

Enter the hour of the event with this format : 'hh:mm'
-> : 18:53
Enter a commentary for the event (max 200 characters) 
(if your commentary lengths is inferior to 199, press enter twice)
-> : Faire à manger                          

we initiate the calendar
```

### Test if an event is correctly deleted from the calendar.

We delete the event at the index 1 (the second event) :

```
State of current calendar : 

| n° |    Date    | Hour  | Commentary 
|----|------------|-------|------------------------------------------------------------------------>
| 0 | 12/04/2024 | 17:00 | Prendre des mouchoirs 
| 1 | 12/04/2024 | 17:30 | Changer de vêtements 
| 2 | 24/05/2024 | 17:00 | Se doucher 

Enter the number of the event you want to delete : 1

You entered : 1 
Event to suppress | 12/04/2024 | 17:30 | Changer de vêtements



You are working with the calendar named : RencontreEnPapouasie
Here are the options available : 

0 - Add an event to your current calendar
1 - Remove an event from your agenda
2 - Show the calendar
3 - Load a calendar
4 - Export your calendar
5 - Quit the application
Current agenda used : "RencontreEnPapouasie"

Enter a number between 0 and 5: 2

Show the calendar

State of current calendar : 

|    Date    | Hour  | Commentary 
|------------|-------|------------------------------------------------------------------------>
| 12/04/2024 | 17:30 | Changer de vêtements 
| 24/05/2024 | 17:00 | Se doucher 


```


### Test if the calendar correctly handles the deletion of the first event.

### Test if the calendar correctly handles the deletion of the last event.

### Test if the calendar correctly handles the deletion of an event that doesn't exist.

### Test if the calendar correctly handles the deletion of an event from an empty calendar.

### Test if the calendar correctly sorts events by date and hour when a new event is added.

### Test if the calendar correctly updates the date and hour of an existing event.



## List of functions and their purpose

