#include<iostream>
#include<vector>

using namespace std;

class student {
	private:
		int key;

	public:
		int marks;
		int roll_no;

		// student(int marks, int roll_no) 
		// {
		// 	this->marks = marks;
		// 	this->roll_no = roll_no;
		// }

		student(int marks)
		{
			this->marks = marks;
		}

		student()
		{
			this->key = 1000;
		}

		void print_detail() 
		{
			cout << "Key is " << key << endl;
			cout<< roll_no << " " << marks << endl;
		}
};


int main(int argc, char** argv)
{
	// this is present on stack
	// student shreesh(95, 10);
	// shreesh.print_detail();

	// now time to make it on heap
	// student* st = new student(99, 22);
	// student *st = new student(99, 22);
	// student* st = new student();
	// st->print_detail();

	// student *st2 = new student();
	vector<int> vec(10);
	cout << vec.capacity();
}