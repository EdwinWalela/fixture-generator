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
