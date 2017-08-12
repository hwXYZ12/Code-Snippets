#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Person {

private:
	std::string name;
	int value;

public:
	Person(std::string & name, int value) : name(name), value(value) {}
	Person(const char * name, int value) : name(name), value(value) {}

	bool operator<(Person & a) {
		return value < a.value;
	}

	int getValue() {
		return value;
	}

	const std::string & getName() {
		return name;
	}

	friend std::ostream & operator<<(std::ostream & os, Person & p) {
		os << "Name: " << p.name << ", Value: " << p.value;
		return os;
	}

};

// takes a sorted list of people (represented as pointers) and an index to one of the elements
// of that list and returns the 3 people with values closest to
// the value of the person at the given index
void getNearestNeighbors(std::vector<Person *> & arrOfPeople,
							int personIndex,
						std::vector<std::string> & neighbors) {
	
	// sanity checks
	if (arrOfPeople.empty()
		|| personIndex < 0
		|| personIndex >= arrOfPeople.size()) {
		return;
	}

	// nearest possible neighbors
	std::vector<Person *> possibleNeighbors = std::vector<Person *>();

	// push at most 6 neighbors into a list
	for (int i = personIndex - 3; i <= personIndex + 3; ++i) {
		if (i != personIndex && i < arrOfPeople.size() && i >= 0) {
			possibleNeighbors.push_back(arrOfPeople[i]);
		}
	}

	// sort neighbors on their absolute distance from the given person's
	// value
	std::sort(possibleNeighbors.begin(), possibleNeighbors.end(), 
		[arrOfPeople,personIndex](Person * a, Person * b) {
		
			return (abs(a->getValue()-arrOfPeople[personIndex]->getValue()) < 
				abs(b->getValue() - arrOfPeople[personIndex]->getValue()));
		}
	);

	// clear neighbors vector
	neighbors.clear();

	// get the smallest three neighbors from the list
	// and push them into the return vector
	for (int i = 0; i < 3 && i < possibleNeighbors.size(); ++i) {
		neighbors.push_back(possibleNeighbors[i]->getName());
	}
	
}

int main() {


	using std::cout;
	using std::endl;

	// generate nearest neighbor array
	std::vector<Person *> people = std::vector<Person *>();

	Person a = Person("will", 2);
	people.push_back(&a);
	cout << a << endl;
	Person b = Person("bob", -4);
	people.push_back(&b);
	cout << b << endl;
	Person c = Person("joe", 20);
	people.push_back(&c);
	cout << c << endl;
	Person d = Person("jill", -3);
	people.push_back(&d);
	cout << d << endl;
	Person e = Person("jack", 200);
	people.push_back(&e);
	cout << e << endl;
	Person f = Person("george", 5);
	people.push_back(&f);
	cout << f << endl;
	Person g = Person("zoe", 7);
	people.push_back(&g);
	cout << g << endl;

	// sort nearest neighbor array
	std::sort(people.begin(), people.end(), [](Person * a, Person * b) { return *a < *b; });

	// print people
	for (auto a : people) {
		cout << *a << endl;
	}

	// print all nearest neighbors
	for (int i = 0; i < people.size(); ++i) {
		auto neighborNames = std::vector<std::string>();
		getNearestNeighbors(people, i, neighborNames);
		cout << "Neighbors : " << i << endl;
		for (auto x : neighborNames) {
			cout << x << endl;
		}
	}

	std::cin.get();

	return 0;
}