
#ifndef content_common_CreateAndBindTempl_h
#define content_common_CreateAndBindTempl_h

#include "mojo/public/cpp/bindings/receiver.h"

namespace content {

template <typename MojoInterface, typename Interface, typename... Pack> void createAndBindBrokerProxy(mojo::ScopedMessagePipeHandle handle, Pack... params)
{
    mojo::Receiver<MojoInterface>* receiver = new mojo::Receiver<MojoInterface>(new Interface(params...));
    mojo::PendingReceiver<MojoInterface> pendingReceiver(std::move(handle));
    receiver->Bind(std::move(pendingReceiver));
    MojoInterface* ptr = receiver->internal_state()->impl();
    receiver->set_disconnect_handler(base::BindOnce(
        [](mojo::Receiver<MojoInterface>* receiver, MojoInterface* ptr) {
            delete ptr; // !!!!!!!!!!!!!!!!!!!!!
            delete receiver;
        },
        base::Unretained(receiver), base::Unretained(ptr)));
}

template <typename MojoInterface, typename Interface, typename... Pack> void createAndBindInterface(mojo::ScopedMessagePipeHandle handle, Pack... params)
{
    createAndBindBrokerProxy<MojoInterface, Interface>(std::move(handle), params...);
}

// template <typename MojoInterface, typename Interface>
// void createAndBindInterface(mojo::ScopedMessagePipeHandle handle, int64_t webviewId)
// {
//     mojo::Receiver<MojoInterface>* receiver = new mojo::Receiver<MojoInterface>(new Interface(webviewId));
//     mojo::PendingReceiver<MojoInterface> pendingReceiver(std::move(handle));
//     receiver->Bind(std::move(pendingReceiver));
//     receiver->set_disconnect_handler(base::BindOnce([](mojo::Receiver<MojoInterface>* receiver) {
//         delete receiver->internal_state()->impl();
//         delete receiver;
//     }, base::Unretained(receiver)));
// }

}

#endif // content_common_CreateAndBindTempl_h
