# Mastering-Web3---The-OOPs-challenge-Programming-Club
First of all I have made a class car having the following properties
1)year
2)model
3)Make
4)speed in x direction
5) speed in y direction
6) x coordinate
7) y coordinate
8) length of car
9) breadth of car
then there is a function accelerate in x direction which increases the speed in x direction by the argument.
similar is the function executed by accelerate in y direction
the move function takes time as an argument and multiplies the speed with time and adds it to the position coordinates
I made a mistake in defining detect_collision and time_to_collision function outside the class, I later realised that this can be corrected using this pointer. Please consider this.
the detect collision functions takes two classes as an argument and checks if there is any overlap in the coordinates, if the two cars have any touching or overlapping points it outputs YES or else NO.
the time_to_collison function also takes two arguments which are car classes. I stored the value given by the detect collision function in an integer y.
If y==0 which means that the range of dimensions of both boxes does not have any common element. In this two cases arise
1) Is the x and y both coordinates of one car greater than the 2nd car or one car has greater x coordinate and the other has greater y coordinate. I used the comment superior in both for the first case and superior in one for the 2nd case.
2) then in the 1st case I checked which car is placed higher on the coordinate plan, if a car is placed higher in the coordinate plane then the relative velocity of the other car with respect to the 1st car should be in the negative direction for collision to take place. After that we can calculate the time taken by the car in x direction and the time in y direction, the final time would be the larger of the above times. 
3) then in the 2nd case in which one car is higher in 1 dimension and the other car in the other dimension. Similarly I have calculated the time in x direction and y direction, if any time comes -ve it shows that the cars would not collide. 
Then we move to y==2 case, this case is obtained when there is an intersection in the length dimensions of the 2 cars but not in the width dimensions, therefore for the time of collision we require the calculations in y direction. This involves the following cases:
1) If both cars move in the same direction: Then I have checked if the velocity direction is +ve, then which car is coordinately placed higher. If car1 is placed higher then relative velocity of 2nd car with respect to the 1st car should be +ve else no collision would take place. Then if the velocity direction of both cars is -ve, then first check which car is place higher . If relative speed in case when car1 is placed higher is +ve no collision will take place, else collision will take place.
2) If both cars move in the opposite direction: If both the cars are moving in opposite directions then it is imperitive that collision will take place, if car 1 is place higher then time would be car1(base)-car2(ceiling) divided by sum of speeds. Similar can be done if car 2 is placed higher.
3) If either of the cars is not moving: If both cars are at rest it is obvious that collision will not take place. Then I have checked if the speed of 1st car is 0, if yes which car is higher. If its car1 then speed of car2 should be +ve else no collision. Similarly if car2 is above then it should have -ve speed. The same explaination can be given for the case when speed of 2nd car is 0.
Then we move to y==3 case, this case is obtained when there is an intersection in the width axis of both cars which means we have to focus our calculations in the x direction, the analysis and cases are similar for y==2 and y==3 case.
And if it y==5 then collision has already taken place, So time of collision would be 0.
Now lets move to the example I took the initial x and y coordinate of 1st car as 0,0 and that of 2nd car as 10,15.Then we gave an impulse to both x and y to give x a velocity of 2 miles/hour in x direction and 2 mile/hour in y direction and for car 2 in x=1 and in y=1. We moved car1 for 3 seconds and car2 for 2 seconds. Therfore we get the coordinates for 1st car as (6,6) and for 2nd car as (12,17). This is the case y==0 where there is no overlap hence in x direction time would be (3 hours) while in y direction it would be 9 hours. Then we can check that after 9 hours with relative velocity car 1 reaches (15,15), then when we again feed it into the detect collision function we can see that the 2 cars collide hence 9 hours is the time for collision.




I forgot to mention the another call to detect collision function, this is to check that the cars actually collide or not after the time we have calculated. So I created a dummy class test1_cpy and test2_cpy and moved them with the velocities that we have calculated and then fed them into the detect collision function to give us the final result.
