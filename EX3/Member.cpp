#include <iostream>
#include <vector>
#include "Member.h"
#include <algorithm>
#include <stdbool.h>
using namespace std;
//using namespace Member;

int Member::numOfMembers = 0;   // count the number of members
int Member::generateId = 0;       // generate a unique id for any member
Member::Member() {
	id = ++generateId;
	numOfMembers++;
	flag = true;                      // boolean variable for destructor
	Followers = new vector<Member>;
	Following = new vector<Member>;

}

Member::~Member() {

	if (flag) {
		numOfMembers--;
		for (Member member : *Following)
			this->unfollow(member);

		for (Member member : *Followers)
			member.unfollow(*this);

		delete this->Following;
		delete this->Followers;
	}
}

void Member::follow(Member m) {

	m.flag = false;
	vector<Member>::iterator it;

	it = std::find(Member::Following->begin(), Member::Following->end(), m);   // check duplicates
	if (it == Member::Following->end()&& !(*this==m)) { 
		Member::Following->push_back(m);
		this->flag = false;
		m.Followers->push_back(*this);
		this->flag = true;
	}

}

void Member::unfollow(Member m) {
	m.flag = false;
	m.Followers->erase(remove(m.Followers->begin(), m.Followers->end(), *this),
			m.Followers->end());
	this->Following->erase(
			remove(this->Following->begin(), this->Following->end(), m),
			this->Following->end());

}

int Member::count() {
	return numOfMembers;
}

int Member::numFollowers() {
	return this->Followers->size();
}

int Member::numFollowing() {
	return this->Following->size();
}
