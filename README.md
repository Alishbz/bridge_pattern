# bridge_pattern

It is a demo of creating a pipeline between two objects with c language without using global data.

In the Demo there is two example particion, 
 1- bridge_pattern_test.c/.h  example
 2- Wifi <-> USB (.c/.h) tasks comminication example -> for do that abstract interface -> bridge.h

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

 # Main Logic

Imagine a container object , name is -> CX_AREA , it can hold any data, or list , or queue. Can be manageable.
 - BRIDGE_OBJ_CREATE( CX_AREA );     -> Create CX_AREA in local area

Imagine a pointer , name is -> CXP, and it hook to CX_AREA, and another pointer to pointer hooks to CXP and its name is -> CXPP.
  -  BRIDGE_CONNECTION_ASSIGN(CX_AREA, namex, wifi , usb );

And this pointers Created with in main tasks object. ->
   - BRIDGE_FIRST_PILE_CREATE( namex );
   - BRIDGE_SECOND_PILE_CREATE( namex ); ( İf you wanna create doubleway)
  

And Of course load the bridges -> 
  - BRIDGE_FIRST_PILE_INIT(namex,me);
  - BRIDGE_SECOND_PILE_INIT(namex,me); ( İf you wanna create doubleway)

Then its ready to connected
  - BRIDGE_GOTO_CROSS(namex, me, wifi_obj_t); (or reverse)

CXPP can reach CXP and it can reach main local area, or reverse. 

And if these are crossed, it becomes a doubleway!


In essence, it's a memory tricking technique, and it's pretty useful. Especially in multi-threaded embedded software projects, you can develop multi-modular software.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------


# Requirements
------
'PURE and OOP C' 
Visual Studio 2022 for test. 
it can be use in every Hardware/PC/Framework.
 
# Contact
------
Created By Ali Sahbaz 
-> ali_sahbaz@outlook.com 
-> [MY LINKEDIN ACCOUNT](https://www.linkedin.com/in/ali-%C5%9Fahbaz-6588a8115/)
