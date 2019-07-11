# Fixtures Generator Algorithim
Algorithm to generate football matches fixtures (Data Structures and Algorithms Term Project)

## Problem
In ABC premier league, there are 10 teams. You have been hired to build a program that will generate
fixtures for these teams based on the following given rules.

1. A team must play every other team twice, i.e. in their home stadium and away stadium. At some
point, teams from the same local town will have to play each other, these teams should only meet
after they have played teams from other local towns.
2. Only 4 teams can play in a given weekend, for example CKlein Stars vs Dolpins FC and Wolves
FC vs SeaHorses FC.
3. While developing the fixtures, indicate the local town, stadium, leg (i.e. 1 or 2) and the weekend
(indicate as weekend #1, weekend #2 etc.) the teams are meant to meet.

Display the final table in a CSV file (and on screen) to show the generated fixtures

| Team Name           | Local Town | Team Stadium  |
| :-----------------: |:----------:|:-------------:|
| Cklein Starts       | Nairobi    | Cklein Arena  |
| Wolves FC           | Nairobi    | Wolves        |
| Dolphins FC         | Mombasa    | Dolphins      |
| Sea Horses FC       | Mombasa    | SHorses Arena |
| Sharks United       | Kisumu     | Sharks Field  |
| Lake Basin FC       | Kisumu     | LBasin        |
| Thika United        | Thika      | Thika Field   |
| Mavuno Comrades FC  | Thika      | Vuno Grounds  |
| Nakuru FC           | Nakuru     | Nakuru Field  |
| Ostrich Associates  | Nakuru     | OAssociates   |


## Solution

1. Read values from input file (Comma Separated Values) while creating `Teams`

2. Pair `Teams` into `Matches`

3. Shuffle the created `Matches` (Fisher-Yates shuffle algorithim)

4. Sort the shuffled `Matches` in acsending order depending on the leg (Ensures first legs are played before second legs)

5. Create `Weekend Games` - Each Weekend has 2 `Matches`

6. Write the generated `Weekend Games`to output file (.csv)

## Data Types

### Team

``` cpp
    struct Team
    {
        std::string name;
        std::string town;
        std::string stadium;
    };
```

### Match

```cpp
    struct Match
    {
        Team home;
        Team away;
        bool derby;
        int leg;
    };
```

### Weekend Game

```cpp
struct Weekend
{
    Match matches[2];
};
```

## Util Class
A utility class which defines the following methods
```cpp
 private:
  bool havePlayedBefore(Team a, Team b); // Check is the teams have played with each other before

 public:
    void readFile(std::string); // Opens a csv file, reads its contents as it creates the teams
    void writeFile(std::string); // Creates a csv file and writes the generated fixtures

    void createMatches(); // Pairs Teams
    void createWeekendGames(); // Pairs Matches 
    void shuffleMatches(); // Shuffles generated Matches (Fisher-Yates shuffle algorithm)
    void sortMatches(); // Sorts Generated Matches' legs' in ascending order (Bubble sort)

    void displayFixtures(); // Dislays generated fixtures on the console
    void displayMatches(); // Display Generated matches on the console
    void printTeams(); // Display Teams read from file
    int getFixturesCount(); // Returns number of fixtures generated
    int getTeamCount(); // Returns number of teams created
```


## Aysmptotic Analysis

###  `void Util::createMatches()`

Time Complexity `O(n^2)` : Nested loop

### `void Util::createWeekendGames()`

Time Complexity O(n) : Single loop

### `void Util::shuffleMatches()`

Time Complexity O(n) : Single loop

### `void Util::sortMatches()`

Time Complexity O(n^2) : Bubble Sort


