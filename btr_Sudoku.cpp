bool backtrack(int k,vector<pair<int,int>> &vp,vector<set<int>> &vec1,vector<set<int>> &vec2,vector<set<int>> &vec3,vector<vector<char>>& arr)
{
    if(k>=vp.size())
    {
        return true;
    }
    int x=vp[k].first;
    int y=vp[k].second;
    for(int i=1;i<=9;i++)
    {
        set<int> s=vec2[x];
        if(s.find(i)!=s.end())
        {
            continue;
        }
        else{
            s=vec3[y];
            if(s.find(i)!=s.end())
            {
                continue;
            }
            else{
                s=vec1[(x/3)*3+y/3];
                if(s.find(i)!=s.end())
                {
                    // cout<<i;
                    continue;
                }
            }
        }
        arr[x][y]=char(i+'0');
        vec2[x].insert(i);
        vec3[y].insert(i);
        vec1[(x/3)*3+y/3].insert(i);
        if(backtrack(k+1,vp,vec1,vec2,vec3,arr)) return true;
        arr[x][y]='.';//this is backtracking only
        vec2[x].erase(vec2[x].find(i));
        vec3[y].erase(vec3[y].find(i));
        vec1[(x/3)*3+y/3].erase(vec1[(x/3)*3+y/3].find(i));
    }
    //this ensures that if this for doesn't run at all then false is returned
    //but does this means that it would return false everytime??
    return false;
}

void Solution::solveSudoku(vector<vector<char> > &arr) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=9;
    //we would use sets..
    //vector of sets to do so
    vector<set<int>> vec1(9);//contains the blocks
    vector<set<int>> vec2(9);//contains the rows..
    vector<set<int>> vec3(9);//contains the cols
    //iterate and put all and then find accordingly
    //first lts write the pseudocode..
    //first make the vector of pairs of the dots that means the dots to be filled
    //then would fill the three vector of sets..
    //
    //recursive funtion with arguments as i as to address the ith pair in the dots vector
    //next would do make the base condition as when i goes beyond it and return true
    //
    //func
    //find for 1 to 9 check in the sets and put at the dot and go forward ..
    //actually put it in the char array and when the next is false change it as well
    //for false we can do in each //that check if we can put a certain integer at the positoin
    //we can do with a bool
    vector<pair<int,int>> vp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]!='.')
            {
                int x=arr[i][j]-'0';
                vec2[i].insert(x);
                vec3[j].insert(x);
                vec1[(i/3)*3+j/3].insert(x);
            }
            else{
                vp.push_back(make_pair(i,j));
            }
        }
    }
    // for(auto i:vp)
    // {
    //     cout<<i.first<<i.second<<endl;
    // }
    backtrack(0,vp,vec1,vec2,vec3,arr);
}
