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

describe("Test String_of_*", ({test}) => {
  test("string_of_player return player one", ({expect}) => {
    expect.equal(string_of_player(PlayerOne),"Player One")
  });
  test("string_of_player return player two", ({expect}) => {
    expect.equal(string_of_player(PlayerTwo),"Player Two")
  });
  test("string_of_point return Love", ({expect}) => {
    expect.equal(string_of_point(Love),"Love (0)")
  });
  test("string_of_point return Fifteen", ({expect}) => {
    expect.equal(string_of_point(Fifteen),"Fifteen (15)")
  });
  test("string_of_point return Thirty", ({expect}) => {
    expect.equal(string_of_point(Thirty),"Thirty (30)")
  });
  test("string_of_score for Point return the score for 0-15", ({expect}) => {
    let loveFifteen = {playerOne: Love, playerTwo: Fifteen}
    expect.equal(string_of_score(Points(loveFifteen)),"Player One:Love (0) ; Player Two:Fifteen (15)")
  });
  test("string_of_score for Forty return the score for 40-30", ({expect}) => {
    let fortyThirty = {player : PlayerOne, otherPlayerPoint : Thirty}
    expect.equal(string_of_score(Forty(fortyThirty)),"Forty (40) for Player One, Player Two get Thirty (30)")
  });
  test("string_of_score for Deuce return deuce", ({expect}) => {
    expect.equal(string_of_score(Deuce),"Deuce !")
  });
  test("string_of_score for Advantage return the advantage of player 2", ({expect}) => {
    expect.equal(string_of_score(Advantage(PlayerTwo)),"Advantage Player Two !")
  });
  test("string_of_score for Game return the game of player 1", ({expect}) => {
    expect.equal(string_of_score(Game(PlayerOne)),"Game Player One !")
  });
});

