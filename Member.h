
#ifndef MEMBER_HPP_
#define MEMBER_HPP_
#include <vector>
using namespace std;

class Member {

	static int numOfMembers;
	static int generateId;
	int id;
	bool flag;
	vector<Member> *Followers;
	vector<Member> *Following;

public:

	Member();
	~Member();
	void follow(Member m);
	void unfollow(Member m);
	int numFollowers();
	int numFollowing();
	bool operator==(const Member &m) const {
		return m.id == id;

	}
	static int count();

};

#endif

