class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        istringstream iss(path);
        string dir;

        while (getline(iss, dir, '/')) {
            if (dir.empty() || dir == ".")
                continue;
            else if (dir == "..") {
                if (!dirs.empty())
                    dirs.pop_back();
            } else {
                dirs.push_back(dir);
            }
        }

        string simplifiedPath = "";
        for (const string& d : dirs) {
            simplifiedPath += "/" + d;
        }

        return simplifiedPath.empty() ? "/" : simplifiedPath;
    }
};
