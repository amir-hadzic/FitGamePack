#include "MenuEntity.h"

namespace Fitgy {
    MenuEntity::MenuEntity(Entity* parent, std::map<std::string, std::string> items, TTF_Font* font)
        : Entity(parent)
    {

        std::map<std::string, std::string>::iterator it;
        for(it = items.begin(); it != items.end(); it++){
            MenuItemEntity* menuItem = new MenuItemEntity(
                this,
                (*it).first,
                (*it).second,
                font
            );

            mMenuItems.push_back(menuItem);
        }
        mPadding = 0;
        redraw();
    }

    MenuEntity::~MenuEntity(){
        mMenuItems.clear();
        onCleanup();
    }

    void
    MenuEntity::redraw(){
        assert(mMenuItems.size() > 0);

        // Set menu items properties.
        for(unsigned int i = 0; i < mMenuItems.size(); i++){
            MenuItemEntity* menuItem = mMenuItems[i];
            menuItem->setPadding(mPadding);
            menuItem->setBackgroundColor(mBackgroundColor);
            menuItem->setBackgroundHoverColor(mBackgroundHoverColor);
            menuItem->setForegroundColor(mForegroundColor);
        }

        // Find the widest menu item.
        int maxWidth = 0;
        for(unsigned int i = 0; i < mMenuItems.size(); i++){
           MenuItemEntity* menuItem = mMenuItems[i];
           if (maxWidth < menuItem->getWidth()){
               maxWidth = menuItem->getWidth();
           }
        }

        // Equalize width of all menu items to the widest one.
        for(unsigned int i = 0; i < mMenuItems.size(); i++){
           MenuItemEntity* menuItem = mMenuItems[i];
           menuItem->setWidth(maxWidth);
        }

        if (entitySurface != NULL){
            SDL_FreeSurface(entitySurface);
            entitySurface = NULL;
        }

        setWidth(maxWidth);
        setHeight(mMenuItems[0]->getHeight() * mMenuItems.size());

        entitySurface = SDL_CreateRGBSurface(
            SDL_HWSURFACE | SDL_SRCALPHA,
            getWidth(),
            getHeight(),
            32, 0, 0, 0, 0
        );

        // Align menu items vertically.
        for(unsigned int i = 0; i < mMenuItems.size(); i++){
            MenuItemEntity* menuItem = mMenuItems[i];
            menuItem->position.setY(menuItem->getHeight() * i);
        }
    }

    void
    MenuEntity::onRender(Entity* entity){
        SDL_FillRect(
            entitySurface,
            NULL,
            SDL_MapRGB(
                entitySurface->format,
                mBackgroundColor.r,
                mBackgroundColor.g,
                mBackgroundColor.b
            )
        );

        for(unsigned int i = 0; i < mMenuItems.size(); i++){
            mMenuItems[i]->onRender(this);
        }

        drawToEntity(entity);
    }

    void
    MenuEntity::setBackgroundColor(SDL_Color color){
        mBackgroundColor = color;
        redraw();
    }

    void
    MenuEntity::setBackgroundHoverColor(SDL_Color color){
        mBackgroundHoverColor = color;
        redraw();
    }

    void
    MenuEntity::setForegroundColor(SDL_Color color){
        mForegroundColor = color;
        redraw();
    }

    void
    MenuEntity::setEventHandler(EventHandler* handler){
        for(unsigned int i = 0; i < mMenuItems.size(); i++){
            mMenuItems[i]->setEventHandler(handler);
        }
    }

    void
    MenuEntity::setPadding(short padding){
        mPadding = padding;
        redraw();
    }
}
