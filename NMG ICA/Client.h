﻿#pragma once
#include <unordered_map>
#include <SFML/Network.hpp>
#include <SFML/Graphics.hpp>

#include "Map.h"
#include "Player.h"
#include "../Shared Files/Data.h"


class Client
{
public:
	static std::unique_ptr<Client> CreateClient(const std::string& username, unsigned short port);

	void Input(float deltaTime);
	void Update(float deltaTime);
	void Render(sf::RenderWindow& window);
	bool Ready() const;
	void SetGameFont(const sf::Font& font);

private:
	sf::IpAddress m_server;
	sf::TcpSocket m_socket;
	std::string m_userName;
	float m_packetDelay;
	float m_packetTimer;
	bool m_playerMoved;

	bool m_gameStarted;
	
	std::unordered_map<std::string, Player> m_players;

	sf::Texture m_carTexture;
	Map m_background;
	sf::Text m_text;

	bool Initialise(unsigned short port);

	void PassCheckPoint(eCheckPoints cp);
	
	bool AddPlayer(const std::string& username);
	bool RemovePlayer(const std::string& username);
	
	bool ReceiveMessage();
	bool SendMessage(eDataPacketType type);
	bool SendMessage(DataPacket& dp);

	Client(const std::string& username);
};
