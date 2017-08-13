// solves this problem (found here http://courses.csail.mit.edu/iap/interview/Hacking_a_Google_Interview_Practice_Questions_Person_A.pdf)
/*Describe an algorithm that takes an unsorted array of axis-aligned rectangles and 
returns any pair of rectangles that overlaps, if there is such a pair.  Axis-aligned 
means that all the rectangle sides are either parallel or perpendicular to the x- and 
y-axis.  You can assume that each rectangle object has two variables in it: the x-y 
coordinates of the upper-left corner and the bottom-right corner.*/

// A scanline solution was given as the correct solution although I believe
// that an array of similar rectangles that share the same center would
// produce n choose 2 pairs which has time complexity O(n^2) to print
// which implies that the given solution cannot have O(nlogn) time in the
// worst case. I may have missed something but given that counter-example I decided
// to use the bruteforce approach.

#include <vector>
#include <utility>

class Rectangle {

private:
	int upperLeftX;
	int upperLeftY;
	int lowerRightX;
	int lowerRightY;

public:
	Rectangle(int x1, int y1, int x2, int y2):upperLeftX(x1),
												upperLeftY(y1),
												lowerRightX(x2),
												lowerRightY(y2){}

	bool contains(Rectangle & other) {
		return (other.upperLeftX >= upperLeftX
			&& other.lowerRightX <= lowerRightX
			&& other.upperLeftY <= upperLeftY
			&& other.lowerRightY >= lowerRightY);
	}
};

// bruteforce solution checks every rectangle pair directly
void bruteForce(std::vector<Rectangle> & rectangles, std::vector<std::pair<Rectangle,Rectangle>> & ret) {

	for (int i = 0; i < rectangles.size(); ++i) {
		for (int j = i + 1; j < rectangles.size(); ++j) {
			if (rectangles[i].contains(rectangles[j])) {
				ret.push_back(std::pair<Rectangle, Rectangle>(rectangles[i], rectangles[j]));
			}
		}
	}
}

int main() {
	return 0;
}