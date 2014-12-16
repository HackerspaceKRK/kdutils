#ifndef __UDP_SERVER_H__
#define __UDP_SERVER_H__

#include <string>
using namespace std;

class IEthernetDataListener
{
public:
	virtual void onEthernetDataReceived(const string& ip, const void* buffer, int len) = 0;
};

class UdpSocket
{
public:
	UdpSocket();
	UdpSocket(int port);
	~UdpSocket();
	
	bool init();
	void close();
	bool process();

	void setListener(IEthernetDataListener* listener)
	{
		m_listener = listener;
	}
	void setPort(int port)
	{
		m_port = port;
	}
	void setTimeout(int timeout)
	{
		m_timeout = timeout;
	}
	
	bool sendData(const string& ip, const void* data, int len);
	
	const string& getLastError() const
	{
		return m_lastErrorStr;
	}

	int getFd() const { return m_sockfd; }
	
private:
	int m_sockfd;
	
	IEthernetDataListener *m_listener;
	int m_port, m_timeout;
	
	string m_lastErrorStr;
};

#endif