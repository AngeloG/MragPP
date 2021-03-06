#ifndef MRAGPP_GAME_H_INCLUDED
#define MRAGPP_GAME_H_INCLUDED

#include "StdH.h"
#include "Window.h"
#include "Renderer.h"
#include "Input.h"
#include "Paths.h"
#include "ContentRegister.h"
#include "Message.h"

MRAGPP_NAMESPACE_BEGIN;

class MRAGPP_EXPORT CGame
{
public:
  Scratch::String gam_strWindowTitle;
  int gam_iWidth;
  int gam_iHeight;
  ULONG gam_ulWindowFlags;

  bool gam_bRunning;

  CWindow Window;
  CRenderer Renderer;
  CInput Input;
  CPaths Paths;
  CContentRegister Content;

  Scratch::String gam_strSystemFont;
  CFont gam_fntSystem;

  bool gam_bCatchMessages;

  unsigned long long gam_iGameUpdate;

public:
  CGame();
  virtual ~CGame();

  void LoadSystemFont(int iSize);

  void Run();
  void Exit();

  virtual void Initialize();
  virtual bool OnClose();

  virtual void Update();
  virtual void Render();

  virtual bool MessageLoop(const CMessage &m);
};

MRAGPP_NAMESPACE_END;

#endif
