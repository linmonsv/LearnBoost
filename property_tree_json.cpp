#include <iostream>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>

int ParseJson()
{
    std::string str = "{\"code\":0,\"images\":[{\"url\":\"fmn057/20111221/1130/head_kJoO_05d9000251de125c.jpg\"},{\"url\":\"fmn057/20111221/1130/original_kJoO_05d9000251de125c.jpg\"}]}";
    using namespace boost::property_tree;

    std::stringstream ss(str);
    ptree pt;
    try{
        read_json(ss, pt);
    }
    catch(ptree_error & e) {
        return 1;
    }

    try{
        int code = pt.get<int>("code");   // 得到"code"的value
        std::cout << "code : " << code << std::endl;

        boost::property_tree::ptree image_array = pt.get_child("images");  // get_child得到数组对象

        BOOST_FOREACH(boost::property_tree::ptree::value_type &v, image_array)
        {
            std::stringstream s;
            write_json(s, v.second);
            std::string image_item = s.str();

            std::cout << "image_item : " << image_item << std::endl;

            {
                std::stringstream ss_img(image_item);
                ptree pt_img;
                read_json(ss_img, pt_img);
                std::string url_dat = pt_img.get<std::string>("url");
                std::cout << "url : " << url_dat << std::endl;
            }


        }
    }
    catch (ptree_error & e)
    {
        std::cout << "2" << std::endl;
        return 2;
    }
    return 0;
}

int ParseJson_2()
{
    std::string str = R"({
   "signalData" : [
      {
         "id" : "CONF_NAME",
         "value" : "PPS_MChip1"
      }
   ],
   "signalType" : "CONFIG"
})";

    std::cout << "str : " << str << std::endl;

    using namespace boost::property_tree;

    std::stringstream ss(str);
    ptree pt;
    try{
        read_json(ss, pt);
    }
    catch(ptree_error & e) {
        return 1;
    }

    try{
        std::string signalType = pt.get<std::string>("signalType");   // 得到"code"的value
        std::cout << "signalType : " << signalType << std::endl;

        boost::property_tree::ptree signalData_array = pt.get_child("signalData");  // get_child得到数组对象

        BOOST_FOREACH(boost::property_tree::ptree::value_type &v, signalData_array)
        {
            std::stringstream s;
            write_json(s, v.second);
            std::string image_item = s.str();

            //std::cout << "data_item : " << image_item << std::endl;

            {
                std::stringstream ss_img(image_item);
                ptree pt_img;
                read_json(ss_img, pt_img);
                std::string id = pt_img.get<std::string>("id");
                std::cout << "id : " << id << std::endl;
                std::string value = pt_img.get<std::string>("value");
                std::cout << "value : " << value << std::endl;
            }


        }
    }
    catch (ptree_error & e)
    {
        std::cout << "2" << std::endl;
        return 2;
    }
    return 0;
}


int ParseJson_3()
{
    std::string str = R"({
   "signalData" : [
      {
         "id" : "9F02",
         "value" : "000000001001"
      },
      {
         "id" : "81",
         "value" : "000005DC"
      },
      {
         "id" : "9F03",
         "value" : "000000000000"
      },
      {
         "id" : "9F04",
         "value" : "00000000"
      },
      {
         "id" : "9F7C",
         "value" : "1234567890EFEFEFEFEFEFEFEFEFEFEFEFEFEFEF"
      },
      {
         "id" : "9F53",
         "value" : "52"
      },
      {
         "id" : "5F2A",
         "value" : "0978"
      },
      {
         "id" : "5F36",
         "value" : "02"
      },
      {
         "id" : "9A",
         "value" : "180930"
      },
      {
         "id" : "9F21",
         "value" : "145558"
      },
      {
         "id" : "9C",
         "value" : "00"
      },
      {
         "id" : "9F33",
         "value" : "60F0C8"
      },
      {
         "id" : "9F35",
         "value" : "22"
      },
      {
         "id" : "9F40",
         "value" : "400080A000"
      },
      {
         "id" : "9F41",
         "value" : "00000508"
      }
   ],
   "signalType" : "ACT"
})";

    std::cout << "str : " << str << std::endl;

    using namespace boost::property_tree;

    std::stringstream ss(str);
    ptree pt;
    try{
        read_json(ss, pt);
    }
    catch(ptree_error & e) {
        return 1;
    }

    try{
        std::string signalType = pt.get<std::string>("signalType");   // 得到"code"的value
        std::cout << "signalType : " << signalType << std::endl;

        boost::property_tree::ptree signalData_array = pt.get_child("signalData");  // get_child得到数组对象

        BOOST_FOREACH(boost::property_tree::ptree::value_type &v, signalData_array)
        {
            std::stringstream s;
            write_json(s, v.second);
            std::string image_item = s.str();

            //std::cout << "data_item : " << image_item << std::endl;

            {
                std::stringstream ss_img(image_item);
                ptree pt_img;
                read_json(ss_img, pt_img);
                std::string id = pt_img.get<std::string>("id");
                std::cout << "id : " << id << " --- ";
                std::string value = pt_img.get<std::string>("value");
                std::cout << "value : " << value << std::endl;
            }


        }
    }
    catch (ptree_error & e)
    {
        std::cout << "2" << std::endl;
        return 2;
    }
    return 0;
}

int InsertJson()
{
    using namespace boost::property_tree;

    ptree pt;

    pt.put("signalType", "TEST");

    ptree exif_array;
    ptree array1, array2, array3;
    array1.put("id", "id_test_1");
    array1.put("value", "value_test_1");
    array2.put("id", "id_test_2");
    array2.put("value", "value_test_2");
    array3.put("id", "id_test_3");
    array3.put("value", "value_test_3");
    exif_array.push_back(std::make_pair("", array1));
    exif_array.push_back(std::make_pair("", array2));
    exif_array.push_back(std::make_pair("", array3));

    pt.put_child("signalData", exif_array);

    std::stringstream s2;
    write_json(s2, pt);
    std::string outstr = s2.str();
    std::cout << "outstr : " << outstr << std::endl;

    return 0;
}

int main()
{
    ParseJson();

    ParseJson_2();

    ParseJson_3();

    InsertJson();

    return 0;
}
