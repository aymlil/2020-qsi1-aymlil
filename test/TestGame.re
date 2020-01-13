open Framework;
open TennisKata.Game;

describe("Test Game transitions", ({test}) => {
  test("Given PlayerOne then PlayerTwo is different", ({expect}) => {
    expect.notEqual(PlayerOne, PlayerTwo)
  })
  test("Given deuce when PlayerTwo wins then score is correct", ({expect}) => {
    expect.equal(scoreWhenDeuce(PlayerTwo), Advantage(PlayerTwo))
  });
});

describe("Test Game Winning",({test}) => {
  test("Given advantage when advantaged player wins then score is correct",
    ({expect}) => {
    let advantagedPlayer = PlayerOne;
    let winner = advantagedPlayer;
    expect.equal(
      scoreWhenAdvantage(advantagedPlayer, winner),
      Game(advantagedPlayer),
    );
  });
  test("Given advantage when the other player wins then score is Deuce",
  ({expect}) => {
    let advantagedPlayer = PlayerOne;
    let winner = other(advantagedPlayer);
    expect.equal(
      scoreWhenAdvantage(advantagedPlayer, winner),
      Deuce,
    );
  });
  test("Given player: 15 | other : 15 when player wins then score is 30/15",
    ({expect}) => {
    let fifteenFifteen = {playerOne: Fifteen, playerTwo: Fifteen};
    let thirtyFifteen = {playerOne: Thirty, playerTwo: Fifteen};
    expect.equal(
      scoreWhenPoints(fifteenFifteen, PlayerOne),
      Points(thirtyFifteen)
    );
  });
  test("Given player: 0 | other : 15 when other wins then score is 0/30",
  ({expect}) => {
    let loveFifteen = {playerOne: Love, playerTwo: Fifteen};
    let loveThirty = {playerOne: Love, playerTwo: Thirty};
    expect.equal(
      scoreWhenPoints(loveFifteen, PlayerTwo), 
      Points(loveThirty)
    );
  });
  test(
    "Given player: 30 | other : 15 when player wins then score is 40/15",
    ({expect}) => {
      let thirtyFifteen = {playerOne: Thirty, playerTwo: Fifteen};
      let fortyFifteen = {player : PlayerOne, otherPlayerPoint : Fifteen} ;
      expect.equal(
      scoreWhenPoints(thirtyFifteen, PlayerOne), 
      Forty(fortyFifteen)
    );
  });
});

