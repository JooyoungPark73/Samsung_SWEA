#include<iostream>

using namespace std;

struct data{
    int input;
    int row;
    int column;
};

data row_column(data);

int main(int argc, char** argv)
{
	int test_case;
	int T = 10000;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        data a, b;
        int a_row, a_row_head = 1, a_column;
        int b_row, b_row_head = 1, b_column;
        int distance, column_diff, row_diff;
        cin >> a.input >> b.input;
        a = row_column(a);
        b = row_column(b);
        row_diff = a.row-b.row;
        column_diff = a.column-b.column;
        if(row_diff*column_diff< 0) distance = abs(a.column-b.column) + abs(a.row-b.row)
        else distance = max(abs(a.column-b.column), abs(a.row-b.row));
        cout << "#" << test_case << " " << distance << endl;
	}
	return 0;
}

data row_column(data input){
    int next_row_head = 1;
    int d=1;
    int prev_row_head=1;
    while(1){
        prev_row_head = next_row_head;
        next_row_head = prev_row_head+d;
        if(input.input < next_row_head)break;
        else d++;
    }
    input.column = input.input-prev_row_head+1;
    input.row = d;
    return input;
}