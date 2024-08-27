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

	characters.forEach(characterUrl => {
		request(characterUrl, function (error, response, body) {
			if (error) {
				console.error(error);
				return;
			}

			const characterData = JSON.parse(body);
			console.log(characterData.name);
		});
	});
});
