class Solution {
public:

    vector<vector<string>> ans;

    unordered_map<string, vector<string>> graph;

    unordered_map<string, int> dist;


    void dfs(string word, string beginWord, vector<string>& path) {

        if (word == beginWord) {

            reverse(path.begin(), path.end());

            ans.push_back(path);

            reverse(path.begin(), path.end());

            return;
        }

        for (string next : graph[word]) {

            path.push_back(next);

            dfs(next, beginWord, path);

            path.pop_back();
        }
    }


    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {

        unordered_set<string> words(
            wordList.begin(),
            wordList.end()
        );


        if (!words.count(endWord)) {
            return {};
        }


        queue<string> q;

        q.push(beginWord);

        dist[beginWord] = 0;


        while (!q.empty()) {

            string word = q.front();

            q.pop();

            int currentDist = dist[word];


            for (int i = 0; i < word.size(); i++) {

                string temp = word;


                for (char c = 'a'; c <= 'z'; c++) {

                    temp[i] = c;


                    if (!words.count(temp)) {
                        continue;
                    }


                    if (!dist.count(temp)) {

                        dist[temp] = currentDist + 1;

                        q.push(temp);

                        graph[temp].push_back(word);
                    }

                    else if (dist[temp] == currentDist + 1) {

                        graph[temp].push_back(word);
                    }
                }
            }
        }


        if (!dist.count(endWord)) {
            return {};
        }


        vector<string> path;

        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};