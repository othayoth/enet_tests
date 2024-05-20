#include <iostream>
#include <cstdlib> 
#include <cstdio>
#include <ctime>

#include "flatbuffers/flatbuffers.h"
#include "robot_msg_generated.h"
#include "monster_generated.h"


using namespace MyGame::Sample;
using namespace RobotFlatBuffer;

// we will need this builder to create the flatbuffer
flatbuffers::FlatBufferBuilder builder(1024);
flatbuffers::FlatBufferBuilder builder_cbot(1024);

void create_monster_buffer(){

    auto weapon_one_name = builder.CreateString("Sword");
    short weapon_one_damage = 3;
    

    auto weapon_two_name = builder.CreateString("Axe");
    short weapon_two_damage = 5;
    
    // Use the `CreateWeapon` shortcut to create Weapons with all the fields set.
    auto sword = CreateWeapon(builder, weapon_one_name, weapon_one_damage);
    auto axe = CreateWeapon(builder, weapon_two_name, weapon_two_damage);

    // Serialize a name for our monster, called "Orc".
    auto name = builder.CreateString("Orc");
 
    // Create a `vector` representing the inventory of the Orc. Each number
    // could correspond to an item that can be claimed after he is slain.
    unsigned char treasure[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto inventory = builder.CreateVector(treasure, 10);


    // Place the weapons into a `std::vector`, then convert that into a FlatBuffer `vector`.
    // how to serialize a vector of tables:
    std::vector<flatbuffers::Offset<Weapon>> weapons_vector;
    weapons_vector.push_back(sword);
    weapons_vector.push_back(axe);
    auto weapons = builder.CreateVector(weapons_vector);

    // vector of structs are serialized differently from table
    Vec3 points[] = { Vec3(1.0f, 2.0f, 3.0f), Vec3(4.0f, 5.0f, 6.0f) };
    auto path = builder.CreateVectorOfStructs(points, 2);

    // Create the position struct
    auto position = Vec3(1.0f, 2.0f, 3.0f);
    
    // Set his hit points to 300 and his mana to 150.
    int hp = 300;
    int mana = 150;
    
    // Finally, create the monster using the `CreateMonster` helper function
    // to set all fields.
    auto orc = CreateMonster(builder, &position, mana, hp, name, inventory,
                            Color_Red, weapons, Equipment_Weapon, axe.Union(),
                            path);

    builder.Finish(orc); 

    std::cout << "created the monster object" << std::endl;
    
}


void create_cbot_buffer(){
    auto obj_a = Createpos_img(builder_cbot, 1.0f, 2.0f);
    auto obj_b = Createpos_img(builder_cbot, 3.0f, 4.0f);
    auto robot_msg = RobotFlatBuffer::Createrobot_msg(builder_cbot, obj_a, obj_b);
    builder_cbot.Finish(robot_msg);
    std::cout << "created the robot message object" << std::endl;
}


int main(int argc, char ** argv)
{

    std::cout << "Hello, World!" << std::endl;

    create_monster_buffer();
    create_cbot_buffer();


    // This must be called after `Finish()`.
    uint8_t *buffer_pointer = builder_cbot.GetBufferPointer();
    int size = builder_cbot.GetSize(); // Returns the size of the buffer that
                              // `GetBufferPointer()` points to.

    

    // reading a flatbuffer
    auto cbot_msg_copy = Getrobot_msg(buffer_pointer);
    auto obj_a_copy = cbot_msg_copy->obj_a();
    auto obj_b_copy = cbot_msg_copy->obj_b();

    std::cout << "Obj 1 x=" << obj_a_copy->x()<< "  y=" << obj_a_copy->y() << std::endl;
    std::cout << "Obj 2 x=" << obj_b_copy->x()<< "  y=" << obj_b_copy->y() << std::endl;
    
    // mutating a mutable flatbuffer
    auto cbot_msg_mutable = GetMutablerobot_msg(buffer_pointer);

    std::cout <<"before mutating" << std::endl;  
    std::cout << "Obj 1 x_new=" << cbot_msg_copy->obj_a()->x()<< "  x_orig=" << cbot_msg_mutable->obj_a()->x() << std::endl;        
  
    cbot_msg_mutable->mutable_obj_a()->mutate_x(10.0f);
    
    std::cout <<"after mutating" << std::endl;      
    std::cout << "Obj 1 x_new=" << cbot_msg_copy->obj_a()->x()<< "  x_orig=" << cbot_msg_mutable->obj_a()->x() << std::endl;        
  


    return 0;

}
