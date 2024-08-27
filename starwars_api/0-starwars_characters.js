#!/usr/bin/node

const request = require('request');

// Get the Movie ID from the first positional argument
const movieId = process.argv[2];

// Define the URL for the Star Wars API for the specific movie
const url = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

request(url, function (error, response, body) {
  if (error) {
    console.error(error);
    return;
  }

  const filmData = JSON.parse(body);
  const characters = filmData.characters;

  // Map each character URL to a promise
  const characterPromises = characters.map(characterUrl => {
    return new Promise((resolve, reject) => {
      request(characterUrl, function (error, response, body) {
        if (error) {
          reject(error);
        } else {
          const characterData = JSON.parse(body);
          resolve(characterData.name);
        }
      });
    });
  });

  // Wait for all promises to resolve
  Promise.all(characterPromises)
    .then(characterNames => {
      characterNames.forEach(name => console.log(name));
    })
    .catch(error => {
      console.error(error);
    });
});
