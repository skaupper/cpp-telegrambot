#ifndef HIDE_COMMAND_H_
#define HIDE_COMMAND_H_

#include "telegram/Command.h"
#include "jsonserializer/RequestConverter.h"


class HideCommand : public telegram::Command
{
    public:
        HideCommand(telegram::TelegramBot &bot, std::string name,
                    telegram::CommandSet *cs) : telegram::Command(bot, name, cs) { }
                    
        virtual bool OnDirect(telegram::structures::Update &update)
        {
            telegram::request::SendMessageParams params(
                update.message->GetChatValue().GetIdValue(), "Hide the keyboard");
            telegram::request::ReplyMarkup replyMarkup;
            replyMarkup.SetReplyKeyboardHide({true});
            params.SetReplyMarkup(replyMarkup);
            bot.SendMessage(params);
            return false;
        }
};

#endif // HIDE_COMMAND_H_
