//methode  1  O(N log N)    
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> v;
        unordered_set <string >visited;
        sort(folder.begin(), folder.end());
        //vector<string> V= { "/a","/a/b","/c/d","/c/d/e","/c/f" };
        //{"/a/b/c", "/a/b/ca", "/a/b/d"}
        for (int i = 0; i < folder.size() ;i++ )
        {
            string str = "";
            int indx = 0;
            bool found = true;
            while (indx < folder[i].size())
            {
                
                if (folder[i][indx] == '/' && visited.count(str))
                {
                    found = false;
                    break;
                }
                str += folder[i][indx];
                indx++;
            }
            if (found)
            {
                v.push_back(folder[i]);
                visited.insert(folder[i]);
            }            
        }
        return v;
    }
};
// int main() {
//     Solution obj;
//     vector<string> V = { "/a","/a/b","/c/d","/c/d/e","/c/f" }; //["/a","/c/d","/c/f"]
//   //  vector<string> V = { "/a", "/a/b/c", "/a/b/d" }; //["/a"]
// //    vector<string> V = {"/a/b/c", "/a/b/ca", "/a/b/d"}; //Output: ["/a/b/c","/a/b/ca","/a/b/d"]
//     obj.removeSubfolders(V);
//     //obj.minLength("CDABCDD");
//     return 0;
// }
