//https://khmt.uit.edu.vn/wecode/truonganpn/assignment/31/128

#include <iostream>
#include <vector>
#include <algorithm>
#define ft(i,a,b) for(int i=a; i<=b; ++i)

using namespace std;

struct record {
	long long goal_for[3], goal_against[3], yellow_card[3];
	long long points = 0, goal_differ = 0, total_yellow_card = 0, total_goal_for = 0;
	void process() {
		for (int i = 0; i < 3; ++i) {
			total_goal_for += goal_for[i];
			goal_differ += goal_for[i] - goal_against[i];
			total_yellow_card += yellow_card[i];
			if (goal_for[i] > goal_against[i]) {
				points += 3;
			}
			else if (goal_for[i] == goal_against[i]) {
				++points;
			}
		}
	}
};

bool cmp(const record& A, const record& B) {
	if (A.points > B.points) {
		return true;
	}
	else if (A.points == B.points) {
		if (A.goal_differ > B.goal_differ) {
			return true;
		}
		else if (A.goal_differ == B.goal_differ) {
			if (A.total_goal_for > B.total_goal_for) {
				return true;
			}
			else if (A.total_yellow_card < B.total_yellow_card) {
				return true;
			}
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	record teamA, teamB;
	ft(i, 0, 2) {
		cin >> teamA.goal_for[i] >> teamA.goal_against[i] >> teamA.yellow_card[i];
	}
	ft(i, 0, 2) {
		cin >> teamB.goal_for[i] >> teamB.goal_against[i] >> teamB.yellow_card[i];
	}
	teamA.process();
	teamB.process();
	if (cmp(teamA, teamB)) {
		cout << teamA.points << " " << teamA.goal_differ << " " << teamA.total_goal_for << " " << teamA.total_yellow_card;
	}
	else {
		cout << teamB.points << " " << teamB.goal_differ << " " << teamB.total_goal_for << " " << teamB.total_yellow_card;
	}
	return 0;
}