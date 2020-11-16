# detection-of-a-super-key-in-DBMS
create a small program to detect the key of a relation in DBMS
Firtfull : you must enter the attributes of a relation;
          for example : Consider a relation R ( A , B , C , D )
          you have to enter A then click (enter) button on your keyboard;
          then B ;
          then C ;
          then D ;
then after entering the attributes, enter the number 0;
              0 ;
now you will have to enter all the functional dependencies;
          for example : 
                          A → B ;
                          B → D ;
                          D → C ;
          the process looks like :
                                        ENTER YOUR FUNCTIONAL DEPENDENCES :
                          ENTER LEFT :A
                          ENTER LEFT :-> (type the " -> " to go through the other side of the functional dependence);
                          ENTER RIGHT :B
                          ENTER RIGHT :0 (type 0 to go through the next functional dependence);
                          ENTER LEFT :C
                          ENTER LEFT :->
                          ENTER RIGHT :D
                          ENTER RIGHT :0
                          ENTER LEFT :D
                          ENTER LEFT :->
                          ENTER RIGHT :C 
                          ENTER RIGHT :00 (when finished the functional dependencies type 00 );
          then the program by itself will tell you at the end what is the key among those attributes ;
