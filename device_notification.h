/**
 * @file   device_notification.h
 * @date   31 Aug 2013
 * @author lukasz.forynski@gmail.com
 * @brief  TODO
 *
 * ___________________________
 * 
 * The MIT License (MIT)
 * 
 * Copyright (c) 2013 Lukasz Forynski
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION 
 */

#ifndef DEVICE_NOTIFICATION_H_
#define DEVICE_NOTIFICATION_H_

#include <device_notif_impl.h>

#include <string>
#include <iostream>



class DeviceNotification
{
public:

    DeviceNotification();

    void init(GUID interface_guid)
    {
        impl->init(interface_guid);
    }

    virtual ~DeviceNotification()
    {
        delete impl;
    }

    void run_from_thread_never_returns()
    {
        impl->run_from_thread_never_returns();
    }

    virtual void device_arrived(const std::string& device_path, void* lparam)
    {
        std::cout << "device arrived: " <<  device_path << "\n";
    }

    virtual void device_removed(const std::string& device_path, void* lparam)
    {
        std::cout << "device removed: " <<  device_path << "\n";
    }

private:
    DeviceNotificationImpl* impl;
};

#endif /* DEVICE_NOTIFICATION_H_ */