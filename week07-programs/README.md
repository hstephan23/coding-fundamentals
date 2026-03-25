# Week 07 - Structs & Modeling

## Learning Goals 

- Group related data 
- Model real-world entities 

### Mental Model 

Structs are blueprints

#### Prompts

- Why do these fields belong together? 

        They are the player data pieces, by making them separate, you have to pass around a lot of different things 
        the issue then becomes trying to track them all. Instead the groupinbg makes sense. 
    
- What does this struct represent in the real world? 

        In a video game, it would represent the coordinates of the player and his/her/their health that they have available to them 


- What would NOT belong in this struct? 

        Probably something like monster health and position 
        Or even the entire map entity