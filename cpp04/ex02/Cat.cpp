/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyanar <ilyanar>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:43:10 by ilyanar           #+#    #+#             */
/*   Updated: 2024/12/12 15:03:57 by ilyanar          ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("chapoter"){
	std::cout << "Cat " << _type << " default constructor called" << std::endl;
	this->idea = new Brain;
	std::string idea[100];
	idea[0] = "Sleep on a cushion";
	idea[1] = "Eat some kibble";
	idea[2] = "Chase an imaginary mouse";
	idea[3] = "Hide in a box";
	idea[4] = "Play with a ball of yarn";
	idea[5] = "Watch birds through the window";
	idea[6] = "Scratch the couch";
	idea[7] = "Climb the curtains";
	idea[8] = "Catch a bug";
	idea[9] = "Knock over a glass of water";
	idea[10] = "Purr loudly";
	idea[11] = "Stare at the human for no reason";
	idea[12] = "Sleep in the sunbeam";
	idea[13] = "Attack a shadow on the wall";
	idea[14] = "Hide under the bed";
	idea[15] = "Chase a laser pointer";
	idea[16] = "Climb to the top of the cat tree";
	idea[17] = "Explore the closet";
	idea[18] = "Demand attention at 3 a.m.";
	idea[19] = "Steal food from the table";
	idea[20] = "Rub against the human’s legs";
	idea[21] = "Drink water from the sink";
	idea[22] = "Play with a dangling string";
	idea[23] = "Knead on a blanket";
	idea[24] = "Chirp at a bird outside";
	idea[25] = "Try to fit into a tiny box";
	idea[26] = "Catch a falling leaf through the window";
	idea[27] = "Nap on a laptop keyboard";
	idea[28] = "Get tangled in a curtain";
	idea[29] = "Explore a new room";
	idea[30] = "Jump into a laundry basket";
	idea[31] = "Knock pens off a desk";
	idea[32] = "Sniff everything new in the house";
	idea[33] = "Pretend to hunt a toy mouse";
	idea[34] = "Stretch dramatically";
	idea[35] = "Hide behind the couch";
	idea[36] = "Demand belly rubs (but bite if given)";
	idea[37] = "Try to climb the human’s legs";
	idea[38] = "Investigate the sound of a plastic bag";
	idea[39] = "Lick an empty plate";
	idea[40] = "Sleep on a human’s chest";
	idea[41] = "Sit on a book being read";
	idea[42] = "Play with the blinds";
	idea[43] = "Watch TV for moving objects";
	idea[44] = "Attempt to catch a bug on the screen";
	idea[45] = "Roll around on the carpet";
	idea[46] = "Bat at dangling earrings";
	idea[47] = "Steal a sock";
	idea[48] = "Push a toy under the couch";
	idea[49] = "Nap in a laundry pile";
	idea[50] = "Hunt the human’s feet under the blanket";
	idea[51] = "Sit in a sunny spot on the floor";
	idea[52] = "Get startled by a cucumber";
	idea[53] = "Poke at a bug";
	idea[54] = "Run around the house randomly";
	idea[55] = "Sleep in a shoebox";
	idea[56] = "Stick head into a shopping bag";
	idea[57] = "Meow loudly at nothing";
	idea[58] = "Climb onto the fridge";
	idea[59] = "Watch fish in an aquarium";
	idea[60] = "Try to catch the vacuum cleaner";
	idea[61] = "Sit on a puzzle in progress";
	idea[62] = "Chase a feather toy";
	idea[63] = "Lick a plastic wrapper";
	idea[64] = "Sit in the sink";
	idea[65] = "Hunt a spider";
	idea[66] = "Steal the human’s chair";
	idea[67] = "Run away from a loud noise";
	idea[68] = "Jump on the dining table";
	idea[69] = "Sleep in the bathroom sink";
	idea[70] = "Chase falling leaves outside";
	idea[71] = "Watch the rain";
	idea[72] = "Try to open a door";
	idea[73] = "Bat at the curtains";
	idea[74] = "Sleep in a pile of towels";
	idea[75] = "Hide in the bathtub";
	idea[76] = "Paw at the TV screen";
	idea[77] = "Snuggle on the couch";
	idea[78] = "Attempt to climb the bookshelf";
	idea[79] = "Meow for food even when fed";
	idea[80] = "Sleep on top of a pile of books";
	idea[81] = "Follow the human to the bathroom";
	idea[82] = "Attack the human’s toes";
	idea[83] = "Curl up on the clean laundry";
	idea[84] = "Peek out from behind furniture";
	idea[85] = "Lick a human’s hand";
	idea[86] = "Nap in a cardboard box";
	idea[87] = "Bat at a fly buzzing around";
	idea[88] = "Sit on top of the cat tree";
	idea[89] = "Jump on the counter";
	idea[90] = "Play with a twist tie";
	idea[91] = "Scratch the door frame";
	idea[92] = "Drink from a dripping faucet";
	idea[93] = "Knock over a vase";
	idea[94] = "Sniff a candle";
	idea[95] = "Climb onto a windowsill";
	idea[96] = "Inspect a shoe";
	idea[97] = "Chirp at the moonlight";
	idea[98] = "Fall asleep while grooming";
	idea[99] = "Dream about chasing mice";
	this->idea->setIdeas(idea);
}

Cat::Cat(const Cat &other) : Animal(other._type){
	std::cout << "Cat " << _type << " copy constructor called" << std::endl;
	this->idea = new Brain(*other.idea);
}

Cat::Cat(std::string type) : Animal(type){
	std::cout << "Cat " << _type << " constructor called" << std::endl;
	this->idea = new Brain;
	std::string idea[100];
	idea[0] = "Sleep on a cushion";
	idea[1] = "Eat some kibble";
	idea[2] = "Chase an imaginary mouse";
	idea[3] = "Hide in a box";
	idea[4] = "Play with a ball of yarn";
	idea[5] = "Watch birds through the window";
	idea[6] = "Scratch the couch";
	idea[7] = "Climb the curtains";
	idea[8] = "Catch a bug";
	idea[9] = "Knock over a glass of water";
	idea[10] = "Purr loudly";
	idea[11] = "Stare at the human for no reason";
	idea[12] = "Sleep in the sunbeam";
	idea[13] = "Attack a shadow on the wall";
	idea[14] = "Hide under the bed";
	idea[15] = "Chase a laser pointer";
	idea[16] = "Climb to the top of the cat tree";
	idea[17] = "Explore the closet";
	idea[18] = "Demand attention at 3 a.m.";
	idea[19] = "Steal food from the table";
	idea[20] = "Rub against the human’s legs";
	idea[21] = "Drink water from the sink";
	idea[22] = "Play with a dangling string";
	idea[23] = "Knead on a blanket";
	idea[24] = "Chirp at a bird outside";
	idea[25] = "Try to fit into a tiny box";
	idea[26] = "Catch a falling leaf through the window";
	idea[27] = "Nap on a laptop keyboard";
	idea[28] = "Get tangled in a curtain";
	idea[29] = "Explore a new room";
	idea[30] = "Jump into a laundry basket";
	idea[31] = "Knock pens off a desk";
	idea[32] = "Sniff everything new in the house";
	idea[33] = "Pretend to hunt a toy mouse";
	idea[34] = "Stretch dramatically";
	idea[35] = "Hide behind the couch";
	idea[36] = "Demand belly rubs (but bite if given)";
	idea[37] = "Try to climb the human’s legs";
	idea[38] = "Investigate the sound of a plastic bag";
	idea[39] = "Lick an empty plate";
	idea[40] = "Sleep on a human’s chest";
	idea[41] = "Sit on a book being read";
	idea[42] = "Play with the blinds";
	idea[43] = "Watch TV for moving objects";
	idea[44] = "Attempt to catch a bug on the screen";
	idea[45] = "Roll around on the carpet";
	idea[46] = "Bat at dangling earrings";
	idea[47] = "Steal a sock";
	idea[48] = "Push a toy under the couch";
	idea[49] = "Nap in a laundry pile";
	idea[50] = "Hunt the human’s feet under the blanket";
	idea[51] = "Sit in a sunny spot on the floor";
	idea[52] = "Get startled by a cucumber";
	idea[53] = "Poke at a bug";
	idea[54] = "Run around the house randomly";
	idea[55] = "Sleep in a shoebox";
	idea[56] = "Stick head into a shopping bag";
	idea[57] = "Meow loudly at nothing";
	idea[58] = "Climb onto the fridge";
	idea[59] = "Watch fish in an aquarium";
	idea[60] = "Try to catch the vacuum cleaner";
	idea[61] = "Sit on a puzzle in progress";
	idea[62] = "Chase a feather toy";
	idea[63] = "Lick a plastic wrapper";
	idea[64] = "Sit in the sink";
	idea[65] = "Hunt a spider";
	idea[66] = "Steal the human’s chair";
	idea[67] = "Run away from a loud noise";
	idea[68] = "Jump on the dining table";
	idea[69] = "Sleep in the bathroom sink";
	idea[70] = "Chase falling leaves outside";
	idea[71] = "Watch the rain";
	idea[72] = "Try to open a door";
	idea[73] = "Bat at the curtains";
	idea[74] = "Sleep in a pile of towels";
	idea[75] = "Hide in the bathtub";
	idea[76] = "Paw at the TV screen";
	idea[77] = "Snuggle on the couch";
	idea[78] = "Attempt to climb the bookshelf";
	idea[79] = "Meow for food even when fed";
	idea[80] = "Sleep on top of a pile of books";
	idea[81] = "Follow the human to the bathroom";
	idea[82] = "Attack the human’s toes";
	idea[83] = "Curl up on the clean laundry";
	idea[84] = "Peek out from behind furniture";
	idea[85] = "Lick a human’s hand";
	idea[86] = "Nap in a cardboard box";
	idea[87] = "Bat at a fly buzzing around";
	idea[88] = "Sit on top of the cat tree";
	idea[89] = "Jump on the counter";
	idea[90] = "Play with a twist tie";
	idea[91] = "Scratch the door frame";
	idea[92] = "Drink from a dripping faucet";
	idea[93] = "Knock over a vase";
	idea[94] = "Sniff a candle";
	idea[95] = "Climb onto a windowsill";
	idea[96] = "Inspect a shoe";
	idea[97] = "Chirp at the moonlight";
	idea[98] = "Fall asleep while grooming";
	idea[99] = "Dream about chasing mice";
	this->idea->setIdeas(idea);
}

Cat::~Cat(){
	std::cout << "Cat " << _type << " destructor called" << std::endl;
	delete idea;
}

Cat& Cat::operator=(const Cat &other){
	if (this != &other){
		Animal::operator=(other);
		this->idea = new Brain(*other.idea);
	}
	return (*this);
}

void Cat::makeSound(void) const{
	std::cout << "Cat " << _type << " say miaouuu!" << std::endl;
}

void	Cat::printIdeas(){this->idea->printIdeas();}
