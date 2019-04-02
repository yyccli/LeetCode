class Solution {
private:
    int h_r[9][9] = {0};
    int h_c[9][9] = {0};
    int h_sub[9][9] = {0};

public:
    void solveSudoku(vector<vector<char>>& board) {
        /*
        Well Impossible for me...
        Create the whole table?
        Then try every single number and check row colum and sub-box
        Backtracking or DFS? recursion...
        */

        // int h_r[9][9] = {0};
        // int h_c[9][9] = {0};
        // int h_sub[9][9] = {0};

        //init table
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                //row
                if(board[i][j] != '.')
                    h_r[i][board[i][j]-'0'-1] = 1;

                //column
                if(board[j][i] != '.')
                    h_c[i][board[j][i]-'0'-1] = 1;

                //sub-box
                if(board[i][j] != '.')
                    h_sub[(i/3)*3+j/3][board[i][j]-'0'-1] = 1;
            }
        }

        int i = 0, j = 0;
        solve(0, 0, board);
    }

    //the problem is when the solve finished, i dont know whether correct or not.
    bool solve(int i, int j, vector<vector<char>>& board) {
	    if (i > 8 || j > 8)
		    return true;

	    if (board[i][j] != '.') {
		    if (j+1 > 8) {
			    return solve(i+1, (j+1)%9, board);
		    } else {
			    return solve(i, j + 1, board);
		    }
	    } else {
		//get all available nums for point(i, j)
		    vector<int> r, c, sub, avai;

		    for (int k = 0; k < 9; k++) {
			    if (h_r[i][k] == 0)
				    r.push_back(k + 1);

			    if (h_c[j][k] == 0)
				    c.push_back(k + 1);

			    if (h_sub[(i / 3) * 3 + j / 3][k] == 0)
				    sub.push_back(k + 1);
		    }

		    vector<int> temp;
		    set_intersection(r.begin(), r.end(), c.begin(), c.end(), back_inserter(temp));
		    set_intersection(temp.begin(), temp.end(), sub.begin(), sub.end(), back_inserter(avai));

		    //all right here. get all nums, then need to find the right num
		    // empty means there is no way to go. go back
		    if (avai.empty())
			    return false;

		    for (int k = 0; k < avai.size(); k++) {
			    board[i][j] = avai[k] + '0';

			    h_r[i][board[i][j] - '0' - 1] = 1;
			    h_c[j][board[i][j] - '0' - 1] = 1;
			    h_sub[(i / 3) * 3 + j / 3][board[i][j] - '0' - 1] = 1;

			    bool isS;
			    if (j + 1 > 8) {
				    isS = solve(i + 1, (j + 1) % 9, board);
			    } else {
				    isS = solve(i, j + 1, board);
			    }

			    if (isS)
				    return true;
			    else {
				    h_r[i][board[i][j] - '0' - 1] = 0;
				    h_c[j][board[i][j] - '0' - 1] = 0;
				    h_sub[(i / 3) * 3 + j / 3][board[i][j] - '0' - 1] = 0;
				    board[i][j] = '.';
			    }
		    }
		    //Emmm done?
		    return false;
	    }

    }

};
