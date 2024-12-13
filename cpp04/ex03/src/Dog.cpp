/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:09:26 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/12 16:45:28 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */


#include "../class/Dog.hpp"

Dog::Dog() : Animal("unknow"){
	std::cout << "Dog " << _type << " default constructor called" << std::endl;
	this->idea = new Brain;
	std::string idea[100];
	idea[0] = "Bark at the mailman";
	idea[1] = "Chase a ball in the yard";
	idea[2] = "Dig a hole in the garden";
	idea[3] = "Beg for food at the table";
	idea[4] = "Chew on a bone";
	idea[5] = "Wag tail happily";
	idea[6] = "Roll over for belly rubs";
	idea[7] = "Sniff everything during a walk";
	idea[8] = "Chase the neighbor's cat";
	idea[9] = "Sleep on the couch";
	idea[10] = "Fetch a stick";
	idea[11] = "Lick the human's face";
	idea[12] = "Play tug-of-war with a rope";
	idea[13] = "Guard the front door";
	idea[14] = "Dig up an old toy";
	idea[15] = "Run in circles excitedly";
	idea[16] = "Watch squirrels through the window";
	idea[17] = "Bark at the vacuum cleaner";
	idea[18] = "Follow the human everywhere";
	idea[19] = "Drink noisily from the water bowl";
	idea[20] = "Chase after a frisbee";
	idea[21] = "Hide under the bed during a storm";
	idea[22] = "Jump up to greet visitors";
	idea[23] = "Sniff another dog at the park";
	idea[24] = "Chew on a slipper";
	idea[25] = "Shake off water after a bath";
	idea[26] = "Herd the kids around the yard";
	idea[27] = "Play in a pile of leaves";
	idea[28] = "Howl at the moon";
	idea[29] = "Carry a stick that's too big";
	idea[30] = "Dig in the sand at the beach";
	idea[31] = "Stand guard by the fence";
	idea[32] = "Chase its own tail";
	idea[33] = "Learn a new trick";
	idea[34] = "Nap in the sun";
	idea[35] = "Bark at the neighbor's dog";
	idea[36] = "Sit by the human's feet";
	idea[37] = "Run through puddles";
	idea[38] = "Wait patiently for treats";
	idea[39] = "Sniff under the couch for crumbs";
	idea[40] = "Carry a toy everywhere";
	idea[41] = "Jump into the car for a ride";
	idea[42] = "Watch TV with the human";
	idea[43] = "Play with a squeaky toy";
	idea[44] = "Lie down on a comfy rug";
	idea[45] = "Chew on a tennis ball";
	idea[46] = "Stand on hind legs for a treat";
	idea[47] = "Catch a ball in the air";
	idea[48] = "Snuggle on the bed";
	idea[49] = "Run around with other dogs";
	idea[50] = "Lick the food bowl clean";
	idea[51] = "Fetch the newspaper";
	idea[52] = "Shake hands with the human";
	idea[53] = "Explore a new trail";
	idea[54] = "Chase after butterflies";
	idea[55] = "Wait by the door for the human";
	idea[56] = "Stick head out the car window";
	idea[57] = "Find a comfy spot to nap";
	idea[58] = "Sniff the laundry basket";
	idea[59] = "Jump into a pile of snow";
	idea[60] = "Scratch an itch with a back leg";
	idea[61] = "Play with a water hose";
	idea[62] = "Try to catch bubbles";
	idea[63] = "Bring a random stick inside";
	idea[64] = "Chase a bike in the street";
	idea[65] = "Roll in the grass";
	idea[66] = "Sneak food off the counter";
	idea[67] = "Snuggle on the human's lap";
	idea[68] = "Watch the human cook";
	idea[69] = "Splash in the kiddie pool";
	idea[70] = "Learn to open the door";
	idea[71] = "Dig in the backyard";
	idea[72] = "Bark at the delivery truck";
	idea[73] = "Carry a shoe to the human";
	idea[74] = "Try to catch a bird";
	idea[75] = "Greet every person with excitement";
	idea[76] = "Sniff every tree in sight";
	idea[77] = "Wait for the human to come home";
	idea[78] = "Watch the human eat";
	idea[79] = "Catch a tennis ball mid-air";
	idea[80] = "Chew on a rawhide bone";
	idea[81] = "Shake the water off after swimming";
	idea[82] = "Sniff a new pair of shoes";
	idea[83] = "Chase a falling leaf";
	idea[84] = "Try to open a treat jar";
	idea[85] = "Nap on the porch";
	idea[86] = "Cuddle up during a movie";
	idea[87] = "Sniff every corner of the house";
	idea[88] = "Jump into a river";
	idea[89] = "Sit proudly after doing a trick";
	idea[90] = "Dig up a hidden treasure";
	idea[91] = "Bring the leash to the human";
	idea[92] = "Chase the human around the yard";
	idea[93] = "Wait under the table for scraps";
	idea[94] = "Run after a car";
	idea[95] = "Guard the human's shoes";
	idea[96] = "Bring a frisbee to play";
	idea[97] = "Jump into the human's bed";
	idea[98] = "Smile after a fun day";
	idea[99] = "Dream about chasing squirrels";
	this->idea->setIdeas(idea);
}

Dog::Dog(std::string type) : Animal(type){
	std::cout << "Dog " << _type << " constructor called" << std::endl;
	this->idea = new Brain;
	std::string idea[100];
	idea[0] = "Bark at the mailman";
	idea[1] = "Chase a ball in the yard";
	idea[2] = "Dig a hole in the garden";
	idea[3] = "Beg for food at the table";
	idea[4] = "Chew on a bone";
	idea[5] = "Wag tail happily";
	idea[6] = "Roll over for belly rubs";
	idea[7] = "Sniff everything during a walk";
	idea[8] = "Chase the neighbor's cat";
	idea[9] = "Sleep on the couch";
	idea[10] = "Fetch a stick";
	idea[11] = "Lick the human's face";
	idea[12] = "Play tug-of-war with a rope";
	idea[13] = "Guard the front door";
	idea[14] = "Dig up an old toy";
	idea[15] = "Run in circles excitedly";
	idea[16] = "Watch squirrels through the window";
	idea[17] = "Bark at the vacuum cleaner";
	idea[18] = "Follow the human everywhere";
	idea[19] = "Drink noisily from the water bowl";
	idea[20] = "Chase after a frisbee";
	idea[21] = "Hide under the bed during a storm";
	idea[22] = "Jump up to greet visitors";
	idea[23] = "Sniff another dog at the park";
	idea[24] = "Chew on a slipper";
	idea[25] = "Shake off water after a bath";
	idea[26] = "Herd the kids around the yard";
	idea[27] = "Play in a pile of leaves";
	idea[28] = "Howl at the moon";
	idea[29] = "Carry a stick that's too big";
	idea[30] = "Dig in the sand at the beach";
	idea[31] = "Stand guard by the fence";
	idea[32] = "Chase its own tail";
	idea[33] = "Learn a new trick";
	idea[34] = "Nap in the sun";
	idea[35] = "Bark at the neighbor's dog";
	idea[36] = "Sit by the human's feet";
	idea[37] = "Run through puddles";
	idea[38] = "Wait patiently for treats";
	idea[39] = "Sniff under the couch for crumbs";
	idea[40] = "Carry a toy everywhere";
	idea[41] = "Jump into the car for a ride";
	idea[42] = "Watch TV with the human";
	idea[43] = "Play with a squeaky toy";
	idea[44] = "Lie down on a comfy rug";
	idea[45] = "Chew on a tennis ball";
	idea[46] = "Stand on hind legs for a treat";
	idea[47] = "Catch a ball in the air";
	idea[48] = "Snuggle on the bed";
	idea[49] = "Run around with other dogs";
	idea[50] = "Lick the food bowl clean";
	idea[51] = "Fetch the newspaper";
	idea[52] = "Shake hands with the human";
	idea[53] = "Explore a new trail";
	idea[54] = "Chase after butterflies";
	idea[55] = "Wait by the door for the human";
	idea[56] = "Stick head out the car window";
	idea[57] = "Find a comfy spot to nap";
	idea[58] = "Sniff the laundry basket";
	idea[59] = "Jump into a pile of snow";
	idea[60] = "Scratch an itch with a back leg";
	idea[61] = "Play with a water hose";
	idea[62] = "Try to catch bubbles";
	idea[63] = "Bring a random stick inside";
	idea[64] = "Chase a bike in the street";
	idea[65] = "Roll in the grass";
	idea[66] = "Sneak food off the counter";
	idea[67] = "Snuggle on the human's lap";
	idea[68] = "Watch the human cook";
	idea[69] = "Splash in the kiddie pool";
	idea[70] = "Learn to open the door";
	idea[71] = "Dig in the backyard";
	idea[72] = "Bark at the delivery truck";
	idea[73] = "Carry a shoe to the human";
	idea[74] = "Try to catch a bird";
	idea[75] = "Greet every person with excitement";
	idea[76] = "Sniff every tree in sight";
	idea[77] = "Wait for the human to come home";
	idea[78] = "Watch the human eat";
	idea[79] = "Catch a tennis ball mid-air";
	idea[80] = "Chew on a rawhide bone";
	idea[81] = "Shake the water off after swimming";
	idea[82] = "Sniff a new pair of shoes";
	idea[83] = "Chase a falling leaf";
	idea[84] = "Try to open a treat jar";
	idea[85] = "Nap on the porch";
	idea[86] = "Cuddle up during a movie";
	idea[87] = "Sniff every corner of the house";
	idea[88] = "Jump into a river";
	idea[89] = "Sit proudly after doing a trick";
	idea[90] = "Dig up a hidden treasure";
	idea[91] = "Bring the leash to the human";
	idea[92] = "Chase the human around the yard";
	idea[93] = "Wait under the table for scraps";
	idea[94] = "Run after a car";
	idea[95] = "Guard the human's shoes";
	idea[96] = "Bring a frisbee to play";
	idea[97] = "Jump into the human's bed";
	idea[98] = "Smile after a fun day";
	idea[99] = "Dream about chasing squirrels";
	this->idea->setIdeas(idea);
}

Dog::Dog(const Dog &other) : Animal(other._type){
	std::cout << "Dog " << _type << " copy constructor called" << std::endl;
	this->idea = new Brain(*other.idea);
}

Dog::~Dog(){
	std::cout << "Dog " << _type << " destructor called" << std::endl;
	delete idea;
}

Dog& Dog::operator=(const Dog &other){
	if (this != &other){
		Animal::operator=(other);
		delete idea;
		this->idea = new Brain(*other.idea);
	}
	return (*this);
}

void Dog::makeSound(void) const{
	std::cout << "Dog " << _type << " say OUAAAFFF!" << std::endl;
}

void	Dog::printIdeas(){this->idea->printIdeas();}
