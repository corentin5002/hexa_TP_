# TP1 : Calendar 

## How to compile and launch the program

Execute `make` in the project folder and then execute with `./main`

## Unit tests

### Test if a new event is added correctly to the calendar.

We create a new event and add it to the calendar.
```
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

### Test if a new event is added correctly at the beginning of the calendar.

```
Add an event to your current calendar

Enter the date of the event with this format : 'dd/mm/yyyy'
-> : 11/03/2024

Enter the hour of the event with this format : 'hh:mm'
-> : 12:00
Enter a commentary for the event (max 200 characters) 
(if your commentary lengths is inferior to 199, press enter twice)
-> : Préparer son avenir

we add an event


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
| 11/03/2024 | 12:00 | Préparer son avenir 
| 12/04/2024 | 17:00 | Prendre des mouchoirs 
| 12/04/2024 | 17:30 | Changer de vêtements 
| 24/05/2024 | 17:00 | Se doucher 
```

### Test if a new event is added correctly at the end of the calendar.

```
Add an event to your current calendar

Enter the date of the event with this format : 'dd/mm/yyyy'
-> : 30/05/2024

Enter the hour of the event with this format : 'hh:mm'
-> : 23:59
Enter a commentary for the event (max 200 characters) 
(if your commentary lengths is inferior to 199, press enter twice)
-> : Faire la fête !

we add an event


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
| 12/04/2024 | 17:00 | Prendre des mouchoirs 
| 12/04/2024 | 17:30 | Changer de vêtements 
| 24/05/2024 | 17:00 | Se doucher 
| 30/05/2024 | 23:59 | Faire la fête ! 
```

### Test if an event is correctly deleted from the calendar.

We delete the event at the index 1 (the second event) :

```
Remove an event from your agenda

State of current calendar : 

| n° |    Date    | Hour  | Commentary 
|----|------------|-------|------------------------------------------------------------------------>
| 00 | 12/04/2024 | 17:00 | Prendre des mouchoirs 
| 01 | 12/04/2024 | 17:30 | Changer de vêtements 
| 02 | 24/05/2024 | 17:00 | Se doucher 

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

```
Remove an event from your agenda

State of current calendar : 

| n° |    Date    | Hour  | Commentary 
|----|------------|-------|------------------------------------------------------------------------>
| 00 | 11/03/2024 | 12:00 | Préparer son avenir 
| 01 | 12/04/2024 | 17:00 | Prendre des mouchoirs 
| 02 | 12/04/2024 | 17:30 | Changer de vêtements 
| 03 | 24/05/2024 | 17:00 | Se doucher 

Enter the number of the event you want to delete : 0

You entered : 0 
Event to suppress | 11/03/2024 | 12:00 | Préparer son avenir



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
| 12/04/2024 | 17:00 | Prendre des mouchoirs 
| 12/04/2024 | 17:30 | Changer de vêtements 
| 24/05/2024 | 17:00 | Se doucher 
```

### Test if the calendar correctly handles the deletion of the last event.

```
Remove an event from your agenda

State of current calendar : 

| n° |    Date    | Hour  | Commentary 
|----|------------|-------|------------------------------------------------------------------------>
| 00 | 12/04/2024 | 17:00 | Prendre des mouchoirs 
| 01 | 12/04/2024 | 17:30 | Changer de vêtements 
| 02 | 24/05/2024 | 17:00 | Se doucher 
| 03 | 30/05/2024 | 23:59 | Faire la fête ! 

Enter the number of the event you want to delete : 3

You entered : 3 
Event to suppress | 30/05/2024 | 23:59 | Faire la fête !



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
| 12/04/2024 | 17:00 | Prendre des mouchoirs 
| 12/04/2024 | 17:30 | Changer de vêtements 
| 24/05/2024 | 17:00 | Se doucher 
```


### Test if the calendar correctly handles the deletion of an event that doesn't exist.

```
Remove an event from your agenda

State of current calendar : 

| n° |    Date    | Hour  | Commentary 
|----|------------|-------|------------------------------------------------------------------------>
| 00 | 12/04/2024 | 17:00 | Prendre des mouchoirs 
| 01 | 12/04/2024 | 17:30 | Changer de vêtements 
| 02 | 24/05/2024 | 17:00 | Se doucher 

Enter the number of the event you want to delete : 4
Invalid input. Please enter a number between 0 and 2.
```



### Test if the calendar correctly handles the deletion of an event from an empty calendar.

```
Enter a number between 0 and 5: 2

Show the calendar

Your calendar is empty


You are working with the calendar named : no named calendar
Here are the options available : 

0 - Add an event to your current calendar
1 - Remove an event from your agenda
2 - Show the calendar
3 - Load a calendar
4 - Export your calendar
5 - Quit the application
Current agenda used : "no named calendar"

Enter a number between 0 and 5: 1

Remove an event from your agenda

Your calendar is empty, you have nothing to remove
```

### Test if the calendar correctly sorts events by date and hour when a new event is added.

We add the event 12/04/2024 17:15 : "Se brosser les dents".

In the list of events, it should be placed between "Prendre des mouchoirs" and "Changer de vêtements".

```
Add an event to your current calendar

Enter the date of the event with this format : 'dd/mm/yyyy'
-> : 12/04/2024

Enter the hour of the event with this format : 'hh:mm'
-> : 17:15
Enter a commentary for the event (max 200 characters) 
(if your commentary lengths is inferior to 199, press enter twice)
-> : Se brosser les dents

we add an event


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
| 12/04/2024 | 17:00 | Prendre des mouchoirs 
| 12/04/2024 | 17:15 | Se brosser les dents 
| 12/04/2024 | 17:30 | Changer de vêtements 
| 24/05/2024 | 17:00 | Se doucher 
```

### Test if the input of the user is correctly handled when he enters a wrong date.

1. We try to add an event with the date 29/02/2024, which is not a valid date.

```
Enter the date of the event with this format : 'dd/mm/yyyy'
-> : 29/02/2024
/!\ Invalid input. Please enter a date with this format : 'dd/mm/yyyy'
```

2. We try to add an event with the date 31/04/2024, which is not a valid date.

```
Enter the date of the event with this format : 'dd/mm/yyyy'
-> : 31/04/2024
/!\ Invalid input. Please enter a date with this format : 'dd/mm/yyyy'
```

3. We try to add an event with the date 12/13/2024, which is not a valid date.

```
Enter the date of the event with this format : 'dd/mm/yyyy'
-> : 12/13/2024
/!\ Invalid input. Please enter a date with this format : 'dd/mm/yyyy'
```

4. We try to add an event with the date 28/02/2023, which is not a valid date.

```
Enter the date of the event with this format : 'dd/mm/yyyy'
-> : 28/02/2023
/!\ Invalid input. Please enter a date with this format : 'dd/mm/yyyy'
```

### Test if the input of the user is correctly handled when he enters a wrong hour.

1. We try to add an event with the hour 24:00, which is not a valid hour.

```
Enter the hour of the event with this format : 'hh:mm'
-> : 24:00
/!\ Invalid input. Please enter an hour with this format : 'hh:mm'
```

2. We try to add an event with the hour 12:60, which is not a valid hour.

```
Enter the hour of the event with this format : 'hh:mm'
-> : 12:60
/!\ Invalid input. Please enter an hour with this format : 'hh:mm'
```

3. We try to add an event with the hour 12:00, which is a valid hour.

``` 
Enter the hour of the event with this format : 'hh:mm'
-> : 12:00
```
It pass to the next step.

4. We try to add an event with the hour 12:0, which is not a valid hour.

```
Enter the hour of the event with this format : 'hh:mm'
-> : 12:0

Enter a commentary for the event (max 200 characters) 
```

**It pass which should not happen.**

## List of functions and their purpose

### List of functions in `library.c`

Here is the list of your functions in `library.c` with their purpose, what they take as argument, and their type of return:

1. `void initiateCalendar(calendarEvent * calendar, int date, int hour, char * description)`
    - Purpose: Initializes the calendar with a single event.
    - Arguments: A pointer to the calendar (`calendarEvent * calendar`), the date (`int date`), the hour (`int hour`), and a description of the event (`char * description`).
    - Return type: `void`

2. `void addEvent(calendarEvent * calendar, int date, int hour, char * description)`
    - Purpose: Adds a new event to the calendar.
    - Arguments: A pointer to the calendar (`calendarEvent * calendar`), the date (`int date`), the hour (`int hour`), and a description of the event (`char * description`).
    - Return type: `void`

3. `calendarEvent * suppressEvent(calendarEvent * calendar, int date, int hour)`
    - Purpose: Deletes an event from the calendar.
    - Arguments: A pointer to the calendar (`calendarEvent * calendar`), the date (`int date`), and the hour (`int hour`) of the event to delete.
    - Return type: `calendarEvent *` - Returns a pointer to the updated calendar.

4. `calendarEvent * openCalendar(char * path, char * calendarName)`
    - Purpose: Opens a saved calendar from a file.
    - Arguments: The path to the file (`char * path`) and a string to store the name of the calendar (`char * calendarName`).
    - Return type: `calendarEvent *` - Returns a pointer to the opened calendar.

5. `void saveCalendar(calendarEvent * calendar, char * path)`
    - Purpose: Saves the current calendar to a file.
    - Arguments: A pointer to the calendar (`calendarEvent * calendar`) and the path to the file (`char * path`).
    - Return type: `void`

6. `void freeCalendar(calendarEvent * calendar)`
    - Purpose: Frees the memory allocated for the calendar.
    - Arguments: A pointer to the calendar (`calendarEvent * calendar`).
    - Return type: `void`

7. `void clearInputBuffer()`
    - Purpose: Clears the input buffer to prevent leftover input from affecting subsequent input operations.
    - Arguments: None.
    - Return type: `void`

8. `int cmpDate(int date1, int date2)`
    - Purpose: Compares two dates.
    - Arguments: The first date (`int date1`) and the second date (`int date2`).
    - Return type: `int` - Returns 1 if the first date is earlier than the second date, 0 otherwise.

### List of functions in `UI_functions.c`

Here is the list of your functions in `UI_functions.c` with their purpose, what they take as argument, and their type of return:

1. `int inputMenu(calendarEvent * calendar, char * nameCalendar)`
    - Purpose: Handles the user input for the main menu of the calendar application.
    - Arguments: A pointer to the calendar (`calendarEvent * calendar`) and a string representing the name of the calendar (`char * nameCalendar`).
    - Return type: `int` - Returns the user's menu selection.

2. `void inputEvent(calendarEvent * calendar)`
    - Purpose: Handles the user input for adding a new event to the calendar.
    - Arguments: A pointer to the calendar (`calendarEvent * calendar`).
    - Return type: `void`

3. `void printCalendar(calendarEvent * calendar)`
    - Purpose: Prints the events in the calendar to the console.
    - Arguments: A pointer to the calendar (`calendarEvent * calendar`).
    - Return type: `void`

4. `int checkDateValue(int day, int month, int year)`
    - Purpose: Checks if a given date is valid.
    - Arguments: The day (`int day`), month (`int month`), and year (`int year`) of the date to check.
    - Return type: `int` - Returns 1 if the date is valid, 0 otherwise.

5. `calendarEvent * inputSupprEvent(calendarEvent * calendar)`
    - Purpose: Handles the user input for deleting an event from the calendar.
    - Arguments: A pointer to the calendar (`calendarEvent * calendar`).
    - Return type: `calendarEvent *` - Returns a pointer to the updated calendar.

6. `char * inputCalendarName()`
    - Purpose: Handles the user input for naming a calendar.
    - Arguments: None.
    - Return type: `char *` - Returns a string representing the name of the calendar.
