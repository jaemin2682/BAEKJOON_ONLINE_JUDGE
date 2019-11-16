#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    int q;
    vector<pair<int, string>> list = {{1967, "DavidBowie"}, {1969, "SpaceOddity"}, {1970, "TheManWhoSoldTheWorld"},
    {1971, "HunkyDory"}, {1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"}, {1973, "AladdinSane"},
    {1973, "PinUps"}, {1974, "DiamondDogs"}, {1975, "YoungAmericans"}, {1976, "StationToStation"},
    {1977, "Low"}, {1977, "Heroes"}, {1979, "Lodger"}, {1980, "ScaryMonstersAndSuperCreeps"}, {1983, "LetsDance"},
    {1984, "Tonight"}, {1987, "NeverLetMeDown"}, {1993, "BlackTieWhiteNoise"}, {1995, "1.Outside"},
    {1997, "Earthling"}, {1999, "Hours"}, {2002, "Heathen"}, {2003, "Reality"}, {2013, "TheNextDay"}, {2016, "BlackStar"}};
    cin >> q;
    for(int i=0;i<q;i++) {
        int s, e;
        cin >> s >> e;
        int num = 0;
        for(int j=0;j<list.size();j++) {
            if(s <= list[j].first && e >= list[j].first) num++;
        }
        cout << num << endl;
        for(int j=0;j<list.size();j++) {
            if(s <= list[j].first && e >= list[j].first) cout << list[j].first << " " << list[j].second << endl;
        }

    }

    return 0;
}