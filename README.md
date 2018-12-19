# Arduinoa-Lift-Elevator
Arduino controlled lift




<EXPLANATION WILL BE ADDED IN THE CODE AS COMMENTS SOON/>
	We made three modules for this project (you can skip to any module you want as the repeated information is mentioned):
<FIRST MODULE>
	The first module is a very simple elevator that has only three floors , thus , there is no need to register many orders at a time , so we made a single variable with identifies where to go. It detects the current floor by measuring the distance between he ground of the elevator and the ground floor , a DC motor to move the car and a H-BRIDGE IC to control the direction of movement and an LCD to display display the current state whether is is moving or reached the desired floor , also it displays the current floor as you reach it and the floor you are going to as you press its button , this module is suitable for small prototype which hight doesn’t exceed 150 cm , thus we changed it as our project is a working elevator that satisfies real-life usage .
</FIRST MODULE>
<SECOND MODULE>
	The second module works by checking the buttons and register any press that happens to an array , it checks if the command is registered before , if so it is dismissed  , then the chip walks through the array that contains the commands (the floors to go to) and goes to every floor by the arrangement of which floor was requested first not by which floor is near to the current position of the car , while doing that task the chip checks the button consistently to make sure that there is no lost command during the elevation , the chip knows the current floor by a potentiometer attached to the motor by custom gear to reduce the speed to a minimum at the area of the potentiometer , it makes some readings that vary by a specific number of revolutions of the motor , and each revolution moves the car a specific distance , by knowing the current revolution we can know the current floor using a custom equation which depends on the distance that the car will move . The LCD is used to display the current state whether is is moving or reached the desired floor , also it displays the current floor as you reach it and the floor you are going to as you press its button .
</SECOND MODULE>
<TO BE ADDED>
	The third module works by checking all the buttons if they are pressed every loop cycle , if there is a pushed button the chip searches an array of orders that has the size of the number of floors in the building/module , if the ordered floor number exists the car won’t register it again , if it doesn’t exist it will register in the nearest empty slot to the start of the array , while empty means has a value of -1 in this module , then rearrange the array to get the nearest floor to the current floor first then the far ones to move to the nearest floor first , then the chip goes through a nested if statements to determine the direction of movement and the car , you can swap the buttons outside the car for two buttons per floor for larger buildings for minor change in the code included as a comment , the car moves using a servo motor and its doors open using another servo motor , this increases the accuracy of current floor detection and the movement between floors , there are some other additional sensors like IR sensor to detect people/things on door , these sensors are read in specific parts of the code such as the delay time (using millis() not delay() as if you use delay() you wont be able to do a task during that time) .
</TO BE ADDED>


