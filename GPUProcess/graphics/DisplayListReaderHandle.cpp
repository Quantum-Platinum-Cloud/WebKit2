/*
 * Copyright (C) 2020 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "DisplayListReaderHandle.h"

namespace WebKit {
using namespace WebCore;

size_t DisplayListReaderHandle::advance(size_t amount)
{
    auto previousUnreadBytes = header().unreadBytes.exchangeSub(amount);
    if (UNLIKELY(previousUnreadBytes < amount)) {
        // FIXME: This should result in terminating the web process.
        RELEASE_ASSERT_NOT_REACHED();
        return 0;
    }
    return previousUnreadBytes - amount;
}

std::unique_ptr<DisplayList::DisplayList> DisplayListReaderHandle::displayListForReading(size_t offset, size_t capacity, DisplayList::ItemBufferReadingClient& client) const
{
    auto displayList = makeUnique<DisplayList::DisplayList>(DisplayList::ItemBufferHandles {{ identifier(), data() + offset, capacity }});
    displayList->setItemBufferClient(&client);
    return displayList;
}

} // namespace WebKit
