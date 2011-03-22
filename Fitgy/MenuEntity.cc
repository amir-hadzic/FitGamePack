#include "MenuEntity.h"

namespace Fitgy {
    MenuEntity::MenuEntity(Entity* parent, TTF_Font* font)
        : Entity(parent)
    {
        mPadding = 0;
        mFont = font;
        mItemEventHandler = NULL;
    }

    MenuEntity::~MenuEntity(){
        std::vector<MenuItemEntity*>::iterator it = mMenuItems.begin();
        while(it != mMenuItems.end()){
            delete (*it);
            *it = NULL;
            ++it;
        }

        delete mItemEventHandler;
    }

    void
    MenuEntity::redraw(){
        if (mMenuItems.size() == 0){
            return;
        }

        // Set menu items properties and find the widest menu item.
        std::vector<MenuItemEntity*>::iterator it = mMenuItems.begin();
        int maxWidth = 0;
        while(it != mMenuItems.end()){
            MenuItemEntity* menuItem = (*it);
            menuItem->setPadding(mPadding);
            menuItem->setBackgroundColor(mBackgroundColor);
            menuItem->setBackgroundHoverColor(mBackgroundHoverColor);
            menuItem->setForegroundColor(mForegroundColor);

            if (maxWidth < menuItem->getWidth()){
                maxWidth = menuItem->getWidth();
            }

            ++it;
        }

        // Equalize width of all menu items to the widest one.
        it = mMenuItems.begin();
        while(it != mMenuItems.end()){
           (*it)->setWidth(maxWidth);
           ++it;
        }

        if (entitySurface != NULL){
            SDL_FreeSurface(entitySurface);
            entitySurface = NULL;
        }

        setWidth(maxWidth);
        setHeight(mMenuItems.front()->getHeight() * mMenuItems.size());

        entitySurface = SDL_CreateRGBSurface(
            SDL_HWSURFACE | SDL_SRCALPHA,
            getWidth(),
            getHeight(),
            32, 0, 0, 0, 0
        );

        // Align menu items in a single column.
        for(unsigned int i = 0; i < mMenuItems.size(); i++){
            MenuItemEntity* menuItem = mMenuItems[i];
            menuItem->position.setY(menuItem->getHeight() * i);
        }
    }

    void
    MenuEntity::onRender(Entity* entity){
        if (entitySurface == NULL){
            return;
        }

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
    MenuEntity::addItem(std::string identifier, std::string text){
        MenuItemEntity* item = new MenuItemEntity(
            this,
            identifier,
            text,
            mFont
        );

        if (mItemEventHandler != NULL){
            item->setEventHandler(mItemEventHandler);
        }

        mMenuItems.push_back(item);
        redraw();
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
        mItemEventHandler = handler;

        std::vector<MenuItemEntity*>::iterator it = mMenuItems.begin();
        while(it != mMenuItems.end()){
            (*it)->setEventHandler(handler);
            ++it;
        }
    }

    void
    MenuEntity::setPadding(short padding){
        mPadding = padding;
        redraw();
    }
}
