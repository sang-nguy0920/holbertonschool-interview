#!/usr/bin/node

// script
const request = require('request');
const process = require('process');

request.get('https://swapi-api.hbtn.io/api/films/' + process.argv[2] + '/', function (err, response, body) {
  if (err) {
    console.log(err);
  }

  const characters = JSON.parse(body).characters;
  const orderedChars = {};

  const whole = JSON.parse(body);
  for (const char of whole.characters) {
    request.get(char, function (err, res, body) {
      const wholeChars = JSON.parse(body);
      if (err) {
        console.log(err);
      } else {
        const characterName = wholeChars.name;
        orderedChars[char] = characterName;
      }
      if (Object.values(orderedChars).length === characters.length) {
        characters.forEach(character => {
          console.log(orderedChars[character]);
        });
      }
    });
  }
});
