/*
	HPE Codewars Taiwan, 2018
    Author: Keng-Yu Lin <kengyu@hpe.com>, 16 Oct 2018
    compile with: gcc v5.4.0 with -std=c11 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

enum {asgard, celestial, groot, human, giant, eternity};

const int transition_tbl[6][6] = {
	{-2,  1, -2,  3,  2,  1},
	{-5, -2,  5,  2,  5, -4},
	{-5, -5,  0,  5, -1, -1},
	{-3, -2, -5,  0,  1,  2},
	{ 5, -3, -2, -1, -3,  1},
	{-5, -4, -5,  2,  4, -1}};

int found;
int current_min_life;

int fix_crystal(int energy, int life) /* consume enegery to fix the crystal */
{
	return energy -= abs(energy % 10) + life;
}

int inc_energy(int energy, int life) /* increment energy from unknown universe */
{
	return energy += life*life % 30;
}

void transition(int energy, int life, int orig_race, int current_race)
{
	/* If current life number > previous found life number, dead end */
	if(life >= current_min_life && current_min_life != 0)
		return;

	if(!(life & 1)) /* if life is an even number */
		energy = fix_crystal(energy, life);

	if(energy < 0)
		energy = inc_energy(energy, life);

	/* Termination Condition */
	if(energy == 0)
	{
		found = 1;
		current_min_life = life;
		return;
	}

	if(energy < 0)
		return;

	/* transition to next life */
	transition(energy + transition_tbl[current_race][asgard], life + 1, current_race, asgard);
	transition(energy + transition_tbl[current_race][celestial], life + 1, current_race, celestial);
	transition(energy + transition_tbl[current_race][groot], life + 1, current_race, groot);
	transition(energy + transition_tbl[current_race][human], life + 1, current_race, human);
	transition(energy + transition_tbl[current_race][giant], life + 1, current_race, giant);
	transition(energy + transition_tbl[current_race][eternity], life + 1, current_race, eternity);
}

int main(int argc, char *argv[])
{
	int init_race, init_energy;

	scanf("%d %d", &init_race, &init_energy);

	transition(init_energy + transition_tbl[init_race][asgard], 1, init_race, asgard);
	transition(init_energy + transition_tbl[init_race][celestial], 1, init_race, celestial);
	transition(init_energy + transition_tbl[init_race][groot], 1, init_race, groot);
	transition(init_energy + transition_tbl[init_race][human], 1, init_race, human);
	transition(init_energy + transition_tbl[init_race][giant], 1, init_race, giant);
	transition(init_energy + transition_tbl[init_race][eternity], 1, init_race, eternity);

	if(current_min_life)
		printf("%d\n", current_min_life);
}

